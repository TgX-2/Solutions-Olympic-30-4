const int maxn = 1e5 + 10;
int n, p;
int a[maxn], b[maxn], c[maxn];
int dpa[maxn], dpb[maxn];

void process() {
    cin >> n >> p;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n) cin >> c[i];

    a[0] = a[n + 1] = 0;
    b[0] = b[n + 1] = 0;
    c[0] = c[n + 1] = 0;
    dpa[0] = dpb[0] = 0;
    
    FOR(i, 1, n + 1) {
        dpa[i] = llongmin;
        dpb[i] = llongmin;
        FOR(j, 1, p) if (i - j >= 0) {
            maxi(dpa[i], dpb[i - j] + b[i]);
            maxi(dpb[i], dpa[i - j] + max(a[i], c[i]));
        }
    }
    cout << max(dpa[n + 1], dpb[n + 1]);
}
