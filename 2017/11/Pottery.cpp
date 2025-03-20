const int maxn = 1e5 + 7;
int t, n, m, a[maxn], b[maxn];

int fa(int taim) {
    int ans = 0;
    FOR(i, 1, n) ans += taim / a[i];
    return ans;
}

int fb(int taim) {
    int ans = 0;
    FOR(i, 1, m) ans += taim / b[i];
    return ans;
}

int f(int taim) {
    int aa = fa(taim);
    int bb = fb(t - taim);
    return min({aa, bb});
}

void process() {
    cin >> t;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> m;
    FOR(i, 1, m) cin >> b[i];

    int l = 0, r = t;
    FOR(i, 1, 200) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (f(mid1) < f(mid2)) l = mid1;
        else r = mid2;
    }

    cout << f(l + r >> 1);
}
