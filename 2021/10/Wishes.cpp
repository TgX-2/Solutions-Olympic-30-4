const int maxn = 1e5 + 7;
int n, m, deg[maxn];
vector<int> g[maxn];

bool vis[maxn];
void dfs(int u) {
    vis[u] = 1;
    for(const int &v : g[u]) if (!vis[v])
        dfs(v);
}

void process() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
    }

    FOR(i, 1, n) {
        sort(all(g[i]));
        g[i].erase(unique(all(g[i])), g[i].end());
    }

    FOR(i, 1, n) {
        for(const int &val : g[i])
            deg[val]++;
    }

    int ans = 0;
    FOR(i, 1, n) if (!deg[i]) {
        dfs(i);
        ans++;
    }

    FOR(i, 1, n) if (!vis[i]) {
        dfs(i);
        ans++;
    }

    cout << ans; 
}
