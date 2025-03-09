
const int maxn = 207;
const int INF = 1e9;
int n, m, a[maxn][maxn];
int dp[maxn * 2][maxn][maxn];
const pair<int, int> dir[2] = {{1, 0}, {0, 1}};

void process() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= n + m; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= m; ++k) {
                dp[i][j][k] = -INF;
            }
        }
    }

    int totalStep = n + m - 2;
    dp[0][1][1] = 0;

    for (int k = 0; k < totalStep; ++k) {
        int min_x1 = max(1, k - m + 2);
        int max_x1 = min(k + 1, n);

        for (int x1 = min_x1; x1 <= max_x1; ++x1) {
            int y1 = k - (x1 - 1) + 1;
            if (y1 < 1 || y1 > m) continue;

            int min_x2 = max(1, k - m + 2);
            int max_x2 = min(k + 1, n);
            for (int x2 = min_x2; x2 <= max_x2; ++x2) {
                int y2 = k - (x2 - 1) + 1;
                if (y2 < 1 || y2 > m || dp[k][x1][x2] == -INF) continue;

                for (int dirr1 = 0; dirr1 < 2; ++dirr1) {
                    int nx1 = x1 + dir[dirr1].first;
                    int ny1 = y1 + dir[dirr1].second;

                    if (nx1 > n || ny1 > m) continue;

                    for (int dirr2 = 0; dirr2 < 2; ++dirr2) {
                        int nx2 = x2 + dir[dirr2].first;
                        int ny2 = y2 + dir[dirr2].second;

                        if (nx2 > n || ny2 > m) continue;
                        if (nx1 == nx2 && ny1 == ny2 && (k + 1 != totalStep)) continue;

                        int suma = 0, sumb = 0;
                        if (!(nx1 == 1 && ny1 == 1) && !(nx1 == n && ny1 == m))
                            suma = a[nx1][ny1];
                        if (!(nx2 == 1 && ny2 == 1) && !(nx2 == n && ny2 == m))
                            sumb = a[nx2][ny2];

                        int sum = suma + sumb;
                        if (dp[k + 1][nx1][nx2] < dp[k][x1][x2] + sum)
                            dp[k + 1][nx1][nx2] = dp[k][x1][x2] + sum;
                    }
                }
            }
        }
    }

    cout << dp[totalStep][n][n] << endl;
}
