int poww(int a, int b, int mod) {
    if (b == 0) return 1;
    int tmp = poww(a, b / 2, mod);
    if (b & 1) return ((tmp * tmp) % mod * a) % mod;
    return (tmp * tmp) % mod; 
}

bool checkComposite(int n, int a, int d, int s) {
    int x = poww(a, d, n);
    if (x == 1 or x == n - 1) return 0;

    FOR(r, 1, s - 1) {
        x = x * x % n;
        if (x == n - 1) return 0;
    }
    return 1;
}

bool checkPrime(int n) {
    if (n < 2) return 0;
    if (n % 2 == 0) return (n == 2);

    int d = n - 1;
    int s = 0;

    while(d % 2 == 0) {
        d /= 2;
        s++;
    }

    vector<int> base = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for(const int &val : base) {
        if (val > n - 2) break;
        if (checkComposite(n, val, d, s)) return 0;
    }
    return 1;
}

bool check(int x) {
    if (x == 1) return 1;
    int xx = sqrt(x);
    if (xx * xx == x) 
        if (checkPrime(xx)) return 1;
    xx = cbrt(x);
    if (xx * xx * xx == x) 
        if (checkPrime(xx)) return 1;
    return 0;
}

vector<int> split(const string &s) {
    vector<int> ret;
    int num = 0;
    FOR(i, 0, len(s) - 1) {
        if (s[i] == ' ') {
            if (check(num)) ret.pb(num);
            num = 0;
        } else num = num * 10 + (s[i] - '0');
    }
    ret.pb(num);
    return ret;
}

int n, m;
vector<int> a, b;

const int maxn = 1007;
int f[maxn][maxn];
int dp(int i, int j) {
    if (i > n or j > m) return 0;
    int &ans = f[i][j];
    if (ans != -1) return ans;

    ans = 0;
    if (a[i] == b[j]) maxi(ans, dp(i + 1, j + 1) + 1);
    maxi(ans, dp(i + 1, j));
    maxi(ans, dp(i, j + 1));
    return ans;
}

void process() {
    string s; 
    getline(cin, s);
    a = split(s); n = len(a) - 1;
    getline(cin, s);
    b = split(s); m = len(b) - 1;

    memo(f, -1);
    cout << dp(0, 0);
}
