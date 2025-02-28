const int maxn = 5e2+7;
int n,m, a[maxn][maxn];

void process() {
    cin >> m >> n;
    int ans = intmin;
    FOR(i, 0, m + 1) FOR(j, 0, n + 1) a[i][j] = intmax;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
    FOR(i, 1, m) FOR(j, 1, n) {
        bool _x; cin >> _x;
        if (_x) {
            ans = max(ans, min({abs(a[i][j] - a[i-1][j]),
                                abs(a[i][j] - a[i+1][j]), 
                                abs(a[i][j] - a[i][j-1]), 
                                abs(a[i][j] - a[i][j+1])})
                    );
        }
    }
    cout << ans;
}
