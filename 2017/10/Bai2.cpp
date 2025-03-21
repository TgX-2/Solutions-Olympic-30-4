const int maxn = 1e6 + 7;
int n, a[maxn];

bool check(int tar) {
    int cnt = 1;
    for(int i = tar; i <= n; i += tar) {
        if (a[i] <= cnt) return 0;
        cnt++;
    }

    return 1;
}

void process() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);

    int l = 1, r = n, ans = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans;
}
