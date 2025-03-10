const int dx[5] = {-2, -2, -1, 1};
const int dy[5] = {1, -1, -2, -2};

const int maxn = 1007;
const int mod  = 1e9;
int n, m, k, q;

bool is[maxn][maxn];
int cnt[maxn][maxn];
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    cnt[x][y] = 1;
    while(!q.empty()) {
        pair<int, int> top = q.front(); q.pop();
        int x = top.fi, y = top.se;
        FOR(i, 0, 3) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 or ny < 1 or nx > m or ny > n or is[nx][ny]) continue;
            cnt[nx][ny] += cnt[x][y];
            cnt[nx][ny] %= mod;
            q.push({nx, ny});
        }
    }
}

void process() {
    cin >> m >> n >> k >> q;
    FOR(i, 1, k) {
        int x, y; cin >> x >> y;
        is[x][y] = 1;
    }

    bfs(m, n);
    while(q--) {
        int x, y; cin >> x >> y;
        cout << cnt[x][y] __ ;
    }
}
