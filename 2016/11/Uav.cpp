const int maxn = 5e5+7;
int n, l, a[maxn];

int ansa = INT_MAX, fa[maxn];
int dq1(int id) {
    if (id == n) return 1;
    int &ans = fa[id];
    if (ans != -1) return ans;
    ans = INT_MAX;
    for(int i = min(n, id + l); i >= id + 1; i--) {
        if (a[i] & 1) {
            ans = min(ans, dq1(i) + 1);
            break;
        }
    }
    return ans;
}

int fb[maxn];


void process() {
    cin >> l >> n;
    for(int i = 2; i < n; i++) 
        cin >> a[i];
    a[n] = 1001;
    a[1] = 1000;

    memset(fa, -1, sizeof fa);
    cout << dq1(1) << "\n";

    fb[n] = a[n];
    int mmax = a[n];
    for(int i = n - 1; i >= 1; i--) {
        fb[i] = INT_MIN;
        if (a[i]%2 == 0) {
            fb[i] = max(fb[i], mmax - a[i]);
            if (i + l <= n) 
                fb[i] = max(fb[i], fb[i+l] + a[i]);
            mmax = max(mmax, fb[i]);
        }
    }
    cout << fb[1];
}
