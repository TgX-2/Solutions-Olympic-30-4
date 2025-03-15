const int maxn = 5e5 + 7;
int n, m, s, k, a[maxn];
vector<pair<int, int>> g[maxn];

class compa {
public:
    bool operator()(const array<int, 3> &a, const array<int, 3> &b) {
        int aLen = a[0], aCost = a[1], aNode = a[2];
        int bLen = b[0], bCost = b[1], bNode = a[2];
        return (aLen == bLen ? (aCost == bCost ? aNode <= bNode : aCost < bCost) : aLen > bLen);
    }
};

bool vis[maxn];
int cost = 0;
void bfs() {
    priority_queue<array<int, 3>, vector<array<int, 3>>, compa> q;
    vis[s] = 1;
    for(const pair<int, int> &val : g[s]) {
        int v = val.fi, w = val.se;
        q.push({w, a[v], v});
    }

    cost += a[s];

    while(!q.empty()) {
        array<int, 3> top = q.top(); q.pop();
        int Len = top[0], Cost = top[1], Node = top[2];

        if (vis[Node]) continue;
        if (cost >= Len) {
            cost += Cost;
            vis[Node] = 1;
            for(const pair<int, int> &val : g[Node]) if (!vis[val.fi]) {
                int v = val.fi, w = val.se;
                q.push({w, a[v], v});
            }
        }
    }
}

int cnt = 0;
bool vis2[maxn];


void dfs(int u) {
    cnt++;
    for(const pair<int, int> &val : g[u]) {
        int v = val.fi, w = val.se;
        if (vis[v]) continue;
        if (vis2[v]) continue;

        if (w > cost) continue;
        vis2[v] = 1;
        dfs(v);
    }
}

void process() {
    cin >> n >> m >> s >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    
    bfs();

    int ans = 0;

    if (k == 1) {
        unordered_set<int> candidate;
        FOR(i, 1, n) if (vis[i]) {
            for(const pair<int, int> &val : g[i]) if (!vis[val.fi])
                candidate.insert(val.fi);     
        }

        for(const int &val : candidate) {
            FOR(i, 1, n) vis2[i] = 0;
            vis2[val] = 1;
            cnt = 0;
            dfs(val);
            maxi(ans, cnt);
            vis2[val] = 0;
        }
    }


    FOR(i, 1, n) ans += vis[i];
    cout << ans;
}
