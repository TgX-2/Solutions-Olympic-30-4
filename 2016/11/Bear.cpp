const int maxn = 1e4 + 7;
const int maxm = 1e5 + 7;

struct val {
    int u, v, c;
    bool operator<(const val& other) const {
        return c < other.c;
    }
} g[maxm];

int par[maxn];

void init(int n) {
    for(int i = 1; i <= n; i++) par[i] = i;
}

int find(int u) {
    return (par[u] == u ? u : par[u] = find(par[u]));
}

bool uni(int u, int v) {
    int a = find(u); 
    int b = find(v);
    if (a == b) return 0;
    par[b] = a;
    return 1;
}

int n, m, s[maxn];

void process() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> s[i];

    for(int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        g[i] = {x, y, 2 * z + s[x] + s[y]};
    }
    init(n);
    sort(g + 1, g + 1 + m);
    int ans =  0;
    for(int i = 1; i <= m; i++) {
        if (uni(g[i].u, g[i].v)) ans += g[i].c;
    }
    cout << ans + s[1];
}
