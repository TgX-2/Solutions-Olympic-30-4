const int maxn = 1e5 + 7;
int n, m, k, deg[maxn];
vector<int> g[maxn];
vector<pair<int, int>> a;

int cnt = 1;
bool vis[maxn];
vector<int> node;

void dfs(int u) {
    node.pb(u);
    vis[u] = 1;
    for(const int &v : g[u]) if (vis[v] == 0) 
        dfs(v); 
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.fi == b.fi ? a.se > b.se : a.fi < b.fi);
}

void process() {
    cin >> n >> m >> k;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    FOR(i, 1, n) if (vis[i] == 0) {
        node.clear();
        dfs(i);
        cnt++;

        vector<pair<int, int>> b;
        for(const int &val : node)
            b.pb({deg[val], len(node)});
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        for(const pair<int, int> &val : b)
            a.pb(val);
    }

    sort(all(a), cmp);

    int cnt = 0, ans = 0, pre = -1, sum = 0;
    for(const pair<int, int> &val : a) {
        if (val.fi != pre) {
            cnt = 1;
            maxi(ans, sum);
            sum = val.se;
        } else {
            if (cnt < k) {
                sum += val.se;
                cnt++;
            }
        }
        pre = val.fi;
    }

    maxi(ans, sum);
    cout << ans;
}
