const int maxn = 1e5 + 7;
int n, k, a[maxn];

namespace sub1 {
    int b[10007];

    void sol() {
        FOR(i, 1, n) b[i] = b[i - 1] + a[i];
        pair<int, int> ans = {0, 0};

        FOR(i, 1, n) FOR(j, i, n) {
            int sum = b[j] - b[i - 1];
            if (sum / (j - i + 1) == k) {
                int lenn = (j - i + 1);
                if (lenn > ans.se) {
                    ans = {i, lenn};
                }
            }
        }

        if (ans.fi == 0) cout << 0 __ ;
        else cout << ans.fi _ ans.se __ ;
    }
};

namespace sub2 {
    cmap<int, vector<int>> pos;
    int b[maxn];

    void sol() {
        FOR(i, 1, n) b[i] = b[i - 1] + a[i];
        pair<int, int> ans = {0, 0};
        pos[0].pb(0);

        int sum = 0;
        FOR(i, 1, n) {
            sum += a[i];
            int tar = sum % k;
            pos[tar].pb(i);

            for(const int &j : pos[tar]) {
                int lenn = i - j;
                if (lenn > ans.se and (b[i] - b[j]) / lenn == k and (b[i] - b[j]) % lenn == 0) {
                    ans = {j + 1, lenn};
                }
            }
        }

        if (ans.fi == 0) cout << 0 __ ;
        else cout << ans.fi _ ans.se __ ;
    }
};


void process() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    if (n <= 10000) sub1::sol();
    sub2::sol();
}
