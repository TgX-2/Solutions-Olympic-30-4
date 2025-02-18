const int maxn = 5e5 + 7;
int n, a[maxn], b[maxn], c[maxn];
map<int, int> m;

bool check(int x, int y, int z) {
    return (x + y > z and y + z > x and z + x > y);
}

int bs(int u, int v, int tar) {
    int l = u, r = v, ans = u;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (check(tar, tar, a[mid])) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int nck(int n) {
    if (n < 3) return 0;
    return (n * (n - 1) / 2 * (n - 2) / 3);
}

int f(int x, int y) { // x la tong so tat ca, y la so luong cua no
    int ans = y * (y - 1) / 2 * (x - y);
    return ans + nck(y);
}

void process() {
    cin >> n;
    FOR(i, 1, n) {
        int x; cin >> x;
        m[x]++;
    }

    int i = 1;
    for(const pair<int, int> &val : m) {
        a[i] = val.fi;
        b[i] = val.se;
        c[i] = c[i - 1] + val.se;
        i++;
    }

    int ans = 0;
    n = len(m);
    FOR(i, 1, n) {
        if (b[i] > 1) {
            int pos = bs(i, n, a[i]);
            ans += f(c[pos], b[i]);
        }
    }
    cout << ans __ ;
}
