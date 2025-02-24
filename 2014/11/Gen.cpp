const int maxn = 1007;
int n, m, f[maxn][maxn];
ull a[maxn], b[maxn];

ull cbrtt(ull x) {
    ull l = 1, r = 2154434, ans;
    while(l <= r) {
        ull mid = (l + r) >> 1;
        if (mid * mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

bool checkPrime(ull x) {
    if (x < 2) return 0;

    for(int i = 2; i <= 5 and i * i <= x; i++) 
        if (x % i == 0) return 0;
    for(ull k = 1; (6 * k + 1) * (6 * k + 1) <= x; k++)
        if (x % (6 * k + 1) == 0 or x % (6 * k + 5) == 0) return 0;
    return 1;
}

bool check(ull x) {
    if (x == 0) return 0;
    ull xx = sqrt(x);
    if (xx * xx == x) return 1;

    xx = cbrtt(x);
    return (xx * xx * xx == x and checkPrime(xx));
}

void split(ull *a, int &n, string s) {
    s = s + ' ';
    ull num = 0;

    FOR(i, 0, len(s) - 1) {
        if (s[i] == ' ') {
            if (check(num)) a[++n] = num;
            num = 0;
        } else num = num * 10 + (s[i] - '0');
    }
}

void process() {
    string s;

    getline(cin, s);
    split(a, n, s);
    getline(cin, s);
    split(b, m, s);

    FOR(i, 1, n) FOR(j, 1, m) {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        if (a[i] == b[j])
            maxi(f[i][j], f[i - 1][j - 1] + 1);
    }

    cout << f[n][m];
}
