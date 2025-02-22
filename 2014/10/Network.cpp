const int maxn= 5e4+7;
int n, m;
vi g[maxn];

int cnt = 0, num[maxn], low[maxn], cau = 0, khop = 0;

void dfs(int u, int p) {
    num[u] = low[u] = ++cnt;
    int node = (p != 0);
    for(auto v : g[u]) if (v != p) {
        if (num[v]) mini(low[u], num[v]);
        else {
            dfs(v, u);
            mini(low[u], low[v]);
            if (low[v] == num[v]) cau++;
            if (low[v] >= num[u]) node++;
        }
    }
    if (node >= 2) khop++;
}

void process() {
    cin >> n >> m;
    FOR(i,1,m) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    FOR(i,1,n) if (!num[i])
        dfs(i, 0);

    cout << m - cau;

}
