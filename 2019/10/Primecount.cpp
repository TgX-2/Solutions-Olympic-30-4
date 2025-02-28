int binpow(int a, int b, int mod) {
    if (b == 0) return 1;
    int tmp = binpow(a, b / 2, mod);
    if (b & 1) return ((tmp * tmp) % mod * a) % mod;
    return (tmp * tmp) % mod; 
}

bool checkComposite(int n, int a, int d, int s) {
    int x = binpow(a, d, n);
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

    vector<int> base = {2, 7, 61};

    for(const int &val : base) {
        if (val > n - 2) break;
        if (checkComposite(n, val, d, s)) return 0;
    }
    return 1;
}

void process() {
    int t; cin >> t;
    while(t--) {
        int l, r; cin >> l >> r;

        int cnt = 0;
        FOR(i, l, r) if (checkPrime(i)) cnt++;
        cout << cnt __ ;
    }
}
