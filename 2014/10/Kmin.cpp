int n;
unordered_set<int> s;

void process() {
    cin >> n;
    FOR(i, 1, n) {
        int x; cin >> x;
        s.insert(x);
    }

    int ans = 1;
    while(1) {
        if (!s.count(ans)) break;
        ans++;
    }

    cout << ans;
}
