const int cost[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int maxn = 1e4 + 7;

namespace sub1 {
    string a, ans = "NO SOLUTION";
    int n;
    bool flag = 0;
    void dp(int id, int rem, bool isless, const string &s = "") {
        if (flag) return;
        if (rem < 0) return;
        if (id > n) {
            if (rem == 0 and isless) {
                flag = 1;
                ans = s;
            }
            return;
        }

        FOR(i, (isless ? 0 : a[id] - '0'), 9) {
            int newrem = rem - cost[i];
            int lenn = n - id;
            if (2 * lenn <= newrem and newrem <= 7 * lenn) 
                dp(id + 1, newrem, (isless or (i > (a[id] - '0'))), s + (char)(i + '0'));
        }

    }

    int f(const string &s) {
        int ans = 0;
        FOR(i, 1, n) ans += cost[s[i] - '0'];
        return ans;
    }

    void sol() {
        cin >> a;
        n = len(a); a = " " + a;
        dp(1, f(a), 0);
        cout << ans;
    }
};
