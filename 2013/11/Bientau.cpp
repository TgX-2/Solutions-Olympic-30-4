const int maxn = 5007;
int n, a[maxn], b[maxn];
int ans = -1;
unordered_map<string, int> mm[2 * maxn];

string f(int x) {
    string ans = to_string(x);
    if (x < 100) return "0" + ans;
    return ans;
}

void compress() {
    FOR(i, 1, n) {
        string s = "";
        FOR(j, i, n) {
            s = s + f(a[j]);
            mm[j - i + 1][s]++;
            if (mm[j - i + 1][s] >= 2) maxi(ans, j - i + 2);
        }
    }
}


void process() {
    cin >> n;
    FOR(i, 1, n) cin >> b[i];

    FOR(i, 1, n - 1) 
        a[i] = (b[i] - b[i + 1]) + 100;
    n--;

    compress();
    cout << ans;
}
