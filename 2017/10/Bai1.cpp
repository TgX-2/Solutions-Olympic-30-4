onst int maxn = 107;
int n, m, a[maxn];
int ans[maxn];

void process() {
    cin >> n >> m;
    FOR(i, 1, m) cin >> a[i];
    deque<int> room;

    int id = 1;
    FOR(i, 1, m) {
        while(a[i] > 1) {
            ans[id] = 2;
            a[i] -= 2;
            id++;
        }

        if (a[i] == 1) {
            if (id > n) {
                ans[room.front()]++;
                room.pop_front();
            } else {
                room.push_back(id);
                ans[id] = 1;
                id++;
            }
        }

    }

    FOR(i, 1, n) cout << ans[i] __ ;
}
