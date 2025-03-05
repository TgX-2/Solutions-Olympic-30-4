int n, m, k;
vector<int> mask, app;
int freq[(1 << 16)];
string s; 

void process() {
    cin >> n >> m >> k;

    FOR(i, 1, n) {
        cin >> s;
        int x = 0;
        FOR(j, 0, len(s) - 1)
            x += (1 << j) * (s[j] - '0');
        freq[x]++;
        app.pb(x);    
    }

    sort(all(app));
    app.erase(unique(all(app)), app.end());

    FOR(mm, 0, (1 << m) - 1) {
        if (__builtin_popcount(mm) == k)
            mask.emplace_back(mm);
    }

    int ans = 0;
    for(const int &val : mask) {
        for(const int &x : app) if (freq[x]) {
            ans += freq[x] * freq[x ^ val];
        }
    }

    cout << ans / 2;
}
