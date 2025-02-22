const int maxn = 1007;
int n, m;
int a[maxn][maxn], b[maxn][maxn];

bool check(int x1, int y1, int x2, int y2) {
    return (b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1] == (x2 - x1 + 1) * (y2 - y1 + 1));
}

int bs(int u, int v, int x1, int y1, int x2) {
    int l = u, r = v, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (check(x1, y1, x2, mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

void process() {
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) {
        cin >> a[i][j];
        b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        if (a[i][j] == 9) b[i][j]++;
    }

    int ans = 0;
    FOR(x1, 1, n) FOR(y1, 1, m) {
        FOR(x2, x1, n) if (check(x1, y1, x2, y1)) {
            int tar = ans / (x2 - x1 + 1);

            int y2 = bs(min(m, y1 + tar), m, x1, y1, x2);
            if (y2 != -1) 
                maxi(ans, (x2 - x1 + 1) * (y2 - y1 + 1));
        } else break;
    }

    cout << ans;
}
