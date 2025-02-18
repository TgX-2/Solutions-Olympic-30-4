const int maxn = 3e5 + 7;
int n, m;
vector<array<int, 3>> g;

bool cmp(const array<int, 3> &a, const array<int, 3> &b) {
    return a[2] < b[2];
}

vector<int> mst;
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

bool merge(int u, int v, int id) {
    int a = find(u);
    int b = find(v);

    if (a == b)
        return 0;

    mst.pb(id);

    if (child[a] > child[b])
        swap(a, b);

    child[a] += child[b];
    par[b] = a;

    return 1;
}

bool merge2(int u, int v, int &edge) {
    int a = find(u);
    int b = find(v);

    if (a == b)
        return 0;

    if (child[a] > child[b])
        swap(a, b);

    child[a] += child[b];
    par[b] = a;
    edge++;
    return 1;
}

void process() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g.pb({u, v, w});
    }

    sort(all(g), cmp);
    init();
    int ans = 0;
    FOR(i, 0, m) {
        int u = g[i][0], v = g[i][1], w = g[i][2];

        if (merge(u, v, i)) {
            ans += w;
        }
    }
    cout << ans ___ ;

    int sum = 0, secans = intmax;
    bool is = 0;
    FOR(i, 0, n - 1) {
        init();
        int edge = 0;


        FOR(j, 0, m - 1) {
            if (j == mst[i])
                continue;

            int u = g[j][0], v = g[j][1], w = g[j][2];

            if (merge2(u, v, edge))
                sum += w;
        }

        if (edge != n - 1) {
            sum = 0;
        } else {
            if (sum > ans)
                mini(secans, sum);
            else if (sum == ans and is == 0) 
                is = 1;
            else if (sum == ans and is == 1)
                secans = sum;

            sum = 0;
        }
    }

    cout << secans;
}
