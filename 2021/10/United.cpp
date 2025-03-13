const int maxn = 1e5 + 7;
int n, a[maxn];

int f[maxn];
int dp(int id) {
    if (id > n) return 0;

    int &ans = f[id];
    if (ans != -1) return ans;

    ans = llongmax;
    vector<int> v;
    FOR(j, id, n) {
        v.pb(a[j]);
        if (len(v) > 1 and v[len(v) - 1] > v[len(v) - 2]) break;

        while (len(v) > 1 and v[len(v) - 1] == v[len(v) - 2]) {
            int x = v[len(v) - 1];
            v.pop_back();
            v.pop_back();

            v.pb(x + 1);
        }

        if (len(v) == 1) 
            mini(ans, dp(j + 1) + 1);
    }

    return ans;
}

void process() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    memo(f, -1);
    cout << dp(1);
}
