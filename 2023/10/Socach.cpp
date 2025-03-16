const int dx[5] = {-2, -2, -1, 1};
const int dy[5] = {1, -1, -2, -2};

const int maxn = 1007;
const int mod  = 1e9;
int n, m, k, q;

bool is[maxn][maxn];
int cnt[maxn][maxn];

int dfs(int u, int v) {
    if (u < 1 or u > m) return 0;
    if (v < 1 or v > n) return 0;

    int &ans = cnt[u][v];
    if (ans != -1) return ans;

    ans = 0;
    FOR(i, 0, 3) {
        int nx = u - dx[i];
        int ny = v - dy[i];

        ans += dfs(nx, ny);
        ans %= mod;
    }

    return ans;
}

void process() {
    cin >> m >> n >> k >> q;

    FOR(i, 1, m) FOR(j, 1, n) cnt[i][j] = -1;
    cnt[m][n] = 1;
    FOR(i, 1, k) {
        int x, y; cin >> x >> y;
        is[x][y] = 1;
        cnt[x][y] = 0;
    }

    while(q--) {
        int x, y; cin >> x >> y;
        cout << dfs(x, y) __ ;
    }
}
