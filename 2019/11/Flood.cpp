const int maxn = 1e3 + 7;
int n, m, k;
char a[maxn][maxn];
pair<int, int> h, g;
vector<pair<int, int>> s;

const int dx[5] = {0, 1, 0, -1};
const int dy[5] = {1, 0, -1, 0};

int cost[maxn][maxn];
void bfs0() {
    FOR(i, 1, n) FOR(j, 1, m) cost[i][j] = llongmax;

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
    for(const pair<int, int> &val : s) {
        cost[val.fi][val.se] = 1;
        q.push({1, val.fi, val.se});
    }

    while(!q.empty()) {
        array<int, 3> top = q.top(); q.pop();
        int cos = top[0], x = top[1], y = top[2];
        if (cos != cost[x][y]) continue;
        FOR(i, 0, 3) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 or nx > n or ny < 1 or ny > m) continue;

            if (cost[nx][ny] > cost[x][y] + 1) {
                cost[nx][ny] = cost[x][y] + 1;
                q.push({cost[nx][ny], nx, ny});
            }
        }
    }

}

int dis[maxn][maxn];
bool bfs(int taim) {    
    FOR(i, 1, n) FOR(j, 1, m) dis[i][j] = llongmax;
    dis[h.fi][h.se] = 0;
    deque<pair<int, int>> q; q.push_front(h);
    while(!q.empty()) {
        pair<int, int> top = q.front(); q.pop_front();
        int x = top.fi, y = top.se;

        FOR(i, 0, 3) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 or nx > n or ny < 1 or ny > m) continue;

            int cos = (cost[nx][ny] <= taim);
            if (dis[nx][ny] > dis[x][y] + cos) {
                dis[nx][ny] = dis[x][y] + cos;

                if (cos == 0) q.push_front({nx, ny});
                else q.push_back({nx, ny});
            }
        }
    }


    return (dis[g.fi][g.se] <= k);
}

void process() {
    cin >> n >> m >> k;
    FOR(i, 1, n) FOR(j, 1, m) {
        cin >> a[i][j];
        if (a[i][j] == 'H') h = {i, j};
        if (a[i][j] == 'S') s.pb({i, j});
        if (a[i][j] == 'G') g = {i, j};
    }
    if (abs(h.fi - g.fi) + abs(h.se - g.se) - 1 <= k) return cout << "-1", void();

    bfs0();

    int l = 1, r = max(n, m), ans = 0;

    while(l <= r) {
        int mid = (l + r) >> 1;
        if (bfs(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << ans;
}
