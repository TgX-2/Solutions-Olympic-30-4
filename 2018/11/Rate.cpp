const int maxn = 3e5+7;
int n, k, a[maxn];
double sum[maxn], minsum[maxn];

bool check(double mid) {
    double mmin = intmax;
    FOR(i,1,n) {
        sum[i] = (a[i] - i * mid);
        mini(mmin, sum[i]);
        minsum[i] = mmin;
    }

    FOR(i,k,n) {
        if (sum[i] - minsum[i - k] >= 0) return 1;
    }
    return 0;
}

void process() {
    cin >> n >> k;

    double l = 0.0, r;

    FOR(i,1,n) {
        int x; cin >> x;
        maxi(r, 1.0 * x);
        a[i] = a[i - 1] + x;
    }

    while(r - l >= 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(6) << l;

}
