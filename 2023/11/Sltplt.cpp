const int maxn = 2e5 + 7;
int n, m;
int deg[maxn];
unordered_set<int> g[maxn];


int tar;
int sz = 0;
int vis[maxn];
bool is = 0;

void dfs(int u) {
    vis[u] = 1;
    sz++;

    FOR(v, 1, n) {
        bool isVis = (g[u].find(v) == g[u].end());
        if (v != u and !vis[v] and isVis)
            dfs(v);
        else if (v != u and vis[v] == 2 and isVis) 
            is = 1;
    }
}

void clrscr() {
    FOR(i, 1, n) {
        g[i].clear();
        vis[i] = 0;
    }
}

void process() {
    int t; cin >> t;
    FOR(tt, 1, t) {
        cin >> n >> m;
        FOR(i, 1, n) deg[i] = n - 1;

        FOR(i, 1, m) {
            int u, v; cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
            deg[u]--;
            deg[v]--;
        }

        vector<int> ans;
        sz = 0;
        FOR(i, 1, n) if (deg[i] > n / 2) {
            sz++;
            vis[i] = 2;
        }

        if (sz != 0) ans.pb(sz);

        FOR(i, 1, n) if (!vis[i]) {
            sz = 0;
            is = 0;
            dfs(i);

            if (is == 1) ans[0] += sz;
            else ans.pb(sz);
        }

        sort(all(ans));
        cout << len(ans) __ ;
        for(const int &val : ans) cout << val ___ ;
        cout __ ;

        if (tt != m) clrscr();
    }
}
