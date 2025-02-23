const int maxn = 1e4 + 7;
const int maxm = 507;
int n, m;
int a[maxn], f[maxn][maxm][4];

/* 
f[i][j][sta] 
    i : thằng đang xét ở vị trí i
    j : đang có j hồ lô
    sta :
        sta = 1 : không chọn a[i] nhưng tự do, không phải trả hồ lô
        sta = 2 : không chọn a[i] nhưng bắt buộc phải trả hồ lô
        sta = 3 : đang chọn a[i]
*/

void process() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) FORD(j, m, 0) {
        f[i][j][1] = max({f[i - 1][j][1], f[i - 1][j][2], f[i - 1][j][3]});
        if (j < m) 
            f[i][j][2] = max({f[i - 1][j + 1][1], f[i - 1][j + 1][2], f[i - 1][j + 1][3]});
        if (j == 1) 
            f[i][j][3] = max(f[i - 1][0][1], f[i - 1][0][2]) + a[i];
        if (j > 1)
            f[i][j][3] = f[i - 1][j - 1][3] + a[i];
    }

    cout << max(f[n][0][1], f[n][0][2]);
}
