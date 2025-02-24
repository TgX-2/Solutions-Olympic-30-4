const int maxn = 1e4 + 7;
int n, p;
vector<pair<int, int>> g[maxn];

namespace sub1 {
    vector<int> dijk(int s1, int s2) {
        vector<int> dis(n + 7, intmax);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        if (s1 == s2) {
            q.push({0, s1});
            dis[s1] = 0;
        } else {
            q.push({0, s1}); 
            q.push({0, s2});
            dis[s1] = dis[s2] = 0; 
        }

        while(!q.empty()) {
            pair<int, int> top = q.top(); q.pop();
            int cost = top.fi, u = top.se;
            if (cost != dis[u]) continue;
            for(const pair<int, int> &val : g[u]) {
                int v = val.fi, w = val.se;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
        return dis;
    }

    vector<int> base, test;

    int f(const vector<int> &v) {
        int ans = 0;
        FOR(i, 1, n) maxi(ans, v[i]);
        return ans;
    }

    void sol() {
        base = dijk(p, p);
        int fbase = f(base);
        int ans = llongmin;    

        FOR(i, 1, n) if (i != p) {
            test = dijk(i, p);
            maxi(ans, fbase - f(test));
        }

        cout << ans;
    }
};



namespace subfull {
    int dis[maxn], h[maxn];

    int dfs(int u, int pre, int cnt) {
        int &ans = dis[u];
        h[u] = cnt;

        for(const pair<int, int> &vv : g[u]) {
            int v = vv.fi, w = vv.se;
            if (v == pre) continue;

            int val = dfs(v, u, cnt + 1) + w;
            if (val > ans) ans = val;
        }
        return ans;
    }

    int get(int u, int v) {
        pair<int, int> val = g[u][v];
        return dis[val.fi] + val.se;
    }

    int find(int u, int pre, int mid) {
        if (dis[u] <= mid) return u;
        int lenn = len(g[u]);
        return find(g[u][lenn - 2].fi, u, mid);
    }

    bool check(int u, int pre, int vx, int cnt, int mid) {
        if (h[u] >= h[vx]) return 1;
        if (cnt > mid and dis[u] - dis[vx] > mid) return 0;
        int lenn = len(g[u]) - 1;

        FOR(i, 0, lenn - 2) {
            pair<int, int> vv = g[u][i];
            if (vv.fi == pre) continue;
            int val = get(u, i);
            if (val + cnt > mid and val + (dis[u] - dis[vx]) > mid) return 0;
        }

        return check(g[u][lenn - 1].fi, u, vx, cnt + g[u][lenn - 1].se, mid);
    }

    bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        return dis[a.fi] + a.se < dis[b.fi] + b.se;
    }


    void sol() {
        dfs(p, 0, 1);

        FOR(i, 1, n) sort(all(g[i]), cmp);

        int lenn = len(g[p]);
        pair<int, int> x = g[p][lenn - 1];

        int ans = -1;
        int l = (lenn > 1 ? get(p, lenn - 2) : 0);
        int r = get(p, lenn - 1);

        while(l <= r) {
            int mid = (l + r) >> 1;
            int vx = find(x.fi, p, mid);

            if (check(x.fi, p, vx, x.se, mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        cout << get(p, lenn - 1) - ans;
    }
};

void process() {
    cin >> n >> p;
    FOR(i, 2, n) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    if (n <= 1000) sub1::sol();
    else subfull::sol();
}
