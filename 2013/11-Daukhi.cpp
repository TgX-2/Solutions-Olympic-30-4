const int maxn = 1007;
int n, m, k;
int a[maxn][maxn], b[maxn][maxn];

int get(int x1, int y1, int x2, int y2) {
    return b[x2][y2] - b[x2][y1 - 1] - b[x1 - 1][y2] + b[x1 - 1][y1 - 1];
}

void process() {
    cin >> n >> m >> k;
    FOR(i, 1, n) FOR(j, 1, m) {
        cin >> a[i][j];
        b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
    }

    int ans = 0;
    FOR(i, 1, n - k + 1) FOR(j, 1, m - k + 1)
        maxi(ans, get(i, j, i + k - 1, j + k - 1));
    cout << ans;
}
