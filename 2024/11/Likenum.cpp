int a, b;

pair<int, int> split(int lenn) {
    int cnt = 0;
    int x = 0, y = 0;
    string bb = '0' + to_string(b);
    FOR(i, 1, len(bb) - 1) {
        if (i <= len(bb) - lenn - 1) x = x * 10 + (bb[i] - '0');
        else y = y * 10 + (bb[i] - '0');
    }

    return {x, y};
}

void process() {
    cin >> a >> b;
    if (a > b) return cout << 0, void();

    pair<int, int> x = split(log10(a) + 1);
    cout << x.fi - (x.se < a);
}
