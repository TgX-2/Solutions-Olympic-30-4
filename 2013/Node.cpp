const int maxn = 1007;
int n;
vector<array<int, 3>> g;

int par[maxn], child[maxn];
void init() {
    FOR(i, 1, n) {
        par[i] = i;
        child[i] = 1;
    }
}

int find(int u) {
    return (u == par[u] ? u : par[u] = find(par[u]));
}

bool merge(int u, int v) {
    int a = find(u);
    int b = find(v);
    if (a == b) return 0;

    if (child[a] > child[b]) swap(a, b);
    child[a] += child[b];
    par[b] = a;
    return 1;
}

bool cmp(const array<int, 3> &a, const array<int, 3> &b) {
    return a[2] < b[2];
}

void process() {
    cin >> n;
    int u, v, w;
    while(cin >> u >> v >> w)
        g.pb({u, v, w});
    
    init();
    int ans = 0;
    sort(all(g), cmp);

    for(const array<int, 3> &val : g) {
        int u = val[0], v = val[1], w = val[2];
        if (merge(u, v)) ans += w;
    }
    
    cout << ans;
}
