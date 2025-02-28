const int maxn = 1007;
int n, m, f[maxn][maxn];
pii mot, hai;
bool vis[maxn][maxn];

void bfs(int x1, int y1) {
    queue<pii> q; q.push({x1, y1});
    vis[x1][y1] = 1;

    while(!q.empty()) {
        auto top = q.front(); q.pop();
        int x = top.fi, y = top.se;
        FOR(i, 0, 7) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 or yy < 1 or xx > n or yy > m or vis[xx][yy]) continue;
            f[xx][yy] = f[x][y] + 1;
            vis[xx][yy] = 1;
            q.push({xx, yy});
        }
    }

    cout << (f[hai.fi][hai.se] ? f[hai.fi][hai.se]  : -1);
}

void process() {
    cin >> n >> m >> mot.fi >> mot.se >> hai.fi >> hai.se;
    bfs(mot.fi, mot.se);
}
