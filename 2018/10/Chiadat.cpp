const int maxn = 507;
int n, a[maxn][maxn];

int get(int x, int y) {
    int aa = a[x][y];
    int bb = a[n][y] - a[x][y];
    int cc = a[x][n] - a[x][y];
    int dd = a[n][n] - a[x][n] - a[n][y] + a[x][y];
    return max({aa, bb, cc, dd}) - min({aa, bb, cc, dd});
}

void process() {
    cin >> n;
    FOR(i,1,n) FOR(j,1,n) {
        int x; cin >> x;
        a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + x;
    }

    int ans = intmax;
    FOR(i,1,n) FOR(j,1,n) 
        mini(ans, get(i, j));
    cout << ans;
}
