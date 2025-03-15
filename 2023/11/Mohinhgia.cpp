const int maxn = 1e6 + 7;
int n, m, a[maxn], b[maxn];

namespace sub1 {
    bool check(int st) {
        vector<pair<int, int>> val;
        FOR(i, st, st + n - 1) 
            val.pb({b[i], i - st + 1});
        

        sort(all(val));
        FOR(i, 0, n - 1) if (val[i].se != a[i + 1]) return 0;
        return 1;
    }

    void sol() {
        FOR(i, 1, n) cin >> a[i];

        vector<int> val;
        FOR(i, 1, m) {
            cin >> b[i];
            val.pb(b[i]);
        }

        sort(all(val));
        val.erase(unique(all(val)), val.end());

        FOR(i, 1, m) 
            b[i] = lower_bound(all(val), b[i]) - val.begin() + 1;

        vector<int> ans;

        FOR(i, 1, m - n + 1)
            if (check(i)) ans.pb(i);

        cout << len(ans) __ ;
        for(const int &val : ans) cout << val ___ ;        
    }
    
};

const int mod  = 2e9 + 11;
pair<int, int> seg[maxn << 2];
int poww[maxn];

namespace sub2 {
    pair<int, int> merge(const pair<int, int> &a, const pair<int, int> &b) {
        int aa = a.fi + b.fi;
        int bb = (a.se * poww[b.fi] + b.se) % mod;
        return {aa, bb};
    }

    void update(int id, int l, int r, int pos, int val) {
        if (pos < l or r < pos) return;
        if (l == r) {
            seg[id].fi = val > 0;
            seg[id].se = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, pos, val);
        update(id << 1 | 1, mid + 1, r, pos, val);
        seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
    }

    void sol() {
        poww[0] = 1;
        int target = 0, tmp = 0;

        FOR(i, 1, n) {
            cin >> a[i];
            a[i]--;
            poww[i] = (poww[i - 1] * n) % mod;
            target = (target * n + a[i]) % mod;
            tmp = (tmp * n + 1) % mod;
        }

        vector<int> val;
        FOR(i, 1, m) {
            cin >> b[i];
            val.pb(b[i]);
        }

        sort(all(val));
        FOR(i, 1, m) b[i] = lower_bound(all(val), b[i]) - val.begin() + 1;

        vector<int> ans;
        FOR(i, 1, n) update(1, 1,  m, b[i], i);
        if ((seg[1].se - tmp + mod) % mod == target) ans.pb(1);

        FOR(i, 2, m - n + 1) {
            update(1, 1, m, b[i - 1], 0);
            update(1, 1, m, b[i + n - 1], i + n - 1);
            if (((seg[1].se - i * tmp) % mod + mod) % mod == target) ans.pb(i);
        }

        cout << len(ans) __ ;
        for(const int &val : ans)
            cout << val ___ ;
    }
};

void process() {
    cin >> n >> m;
    if (n <= 100 and m <= 100) sub1::sol();
    else sub2::sol();
}
