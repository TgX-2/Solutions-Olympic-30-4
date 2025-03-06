const int maxn = 2e5 + 7;
int n, m, q;
int deg[maxn];
unordered_set<int> g[maxn];

bool is(const unordered_set<int> &a, const unordered_set<int> &b, const int &y) {
    if (a.count(y)) return 1;
    for(const int &val : a) if (b.count(val)) return 1;
    return 0;
}

void process() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++;
        deg[v]++;
    }

    cin >> q;
    while(q--) {
        int typ, u, v; cin >> typ >> u >> v;
        if (typ == 1) {
            g[u].insert(v);
            g[v].insert(u);
            deg[u]++;
            deg[v]++;
        } else {
            if (deg[u] < deg[v]) 
                cout << (is(g[u], g[v], v) ? "YES" : "NO") __ ;
            else cout << (is(g[v], g[u], u) ? "YES" : "NO") __ ;
        }
    }
}
