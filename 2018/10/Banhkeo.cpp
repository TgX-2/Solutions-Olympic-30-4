const int maxn = 1e5+7;
vector<pair<int, int> g[maxn];
int n, m, k, p = intmax, cnt = 0;
bool vis[maxn];

void dfs(int u, int pre) {
    vis[u] = 1;
    for(auto x : g[u]) if (!vis[x.fi]) {
        if (x.se >= p) dfs(x.fi, u);
    }
}

void process() {
    cin >> n >> m >> k;
    FOR(i,1,k) {
        int x; cin >> x;
        mini(p, x);
    }

    FOR(i,1,m) {
        int x, y, z; cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
    }

    FOR(i,1,n) if (!vis[i]) {
        cnt++;
        dfs(i,0);
    }
    cout << cnt;

}
