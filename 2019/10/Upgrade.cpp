const int maxn = 1e5 + 7;
int n, m;
vector<pair<int, int>> g[maxn];
vector<array<int, 3>> edge;
int cnt[maxn][2], dis[maxn][2];

void dijk(int sta, bool is) {
    FOR(i, 1, n) dis[i][is] = intmax;
    dis[sta][is] = 0;
    cnt[sta][is] = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({dis[sta][is], sta});

    while(!q.empty()) {
        pair<int, int> top = q.top(); q.pop();
        int cost = top.fi, u = top.se;
        if (cost != dis[u][is]) continue;

        for(const pair<int, int> &val : g[u]) {
            int v = val.fi, w = val.se;
            if (dis[v][is] > dis[u][is] + w) {
                dis[v][is] = dis[u][is] + w;
                cnt[v][is] = cnt[u][is];
                q.push({dis[v][is], v});
            } else if (dis[v][is] == dis[u][is] + w) 
                cnt[v][is] += cnt[u][is];
        }
    }
}

set<pair<int, int>> ans;

void sol() {
    for(const array<int, 3> &val : edge) {
        int u = val[0], v = val[1], w = val[2];
        if (dis[u][0] + dis[v][1] + w == dis[n][0] or 
            dis[v][0] + dis[u][1] + w == dis[n][0])
            if (cnt[u][0] == cnt[v][0] and cnt[u][1] == cnt[v][1]) {
                if (u > v) swap(u, v);
                ans.insert({u, v});
            }
    }

    cout << len(ans);
}

void process() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
        edge.pb({u, v, w});
    }

    dijk(1, 0);
    dijk(n, 1);
    sol();
}
