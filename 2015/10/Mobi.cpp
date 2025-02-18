const int maxn = 5e6 + 7;
int n, k, a[maxn];

void process() {
    cin >> n >> k;
    int m = 0;
    FOR(i, 1, n) {
        int x, y; cin >> x >> y;
        a[x] = y;
        maxi(m, x);
    }

    int ans = 0, cursum = 0;
    FOR(i, 0, k << 1) 
        cursum += a[i];
    
    FOR(i, k + 1, m - k + 1) {
        maxi(ans, cursum);
        cursum -= a[i - k - 1];
        cursum += a[i + k];
    }
    maxi(ans, cursum);
    cout << ans;
}
