const int maxn = 1e5 + 7;
int n, k, a[maxn];
vector<int> g[maxn];


int child[maxn], par[maxn];
void build_dfs(int u, int pre) {
    child[u] = 1;
    par[u] = pre;
    for(const int &v : g[u]) if (v != pre) {
        build_dfs(v, u);
        child[u] += child[v];
    }
}

int hld[maxn], hldDep[maxn], dep[maxn], sta[maxn], id[maxn], cnt = 0;
void build_hld(int u, int pre, bool inChain) {
    dep[u] = dep[pre] + 1;
    hldDep[u] = hldDep[pre] + 1;
    if (inChain) hldDep[u] = hldDep[pre];

    hld[cnt] = u;
    id[u] = cnt;
    sta[u] = cnt++;
    if (inChain) sta[u] = sta[pre];

    int bigChild = -1;
    for(const int &v : g[u]) if (v != pre) 
        if (bigChild == -1 or child[bigChild] < child[v]) 
            bigChild = v;

    if (bigChild != -1) build_hld(bigChild, u, 1);

    for(const int &v : g[u])  
        if (v != pre and v != bigChild) 
            build_hld(v, u, 0);

}

int hldPar(int u) {
    return par[hld[sta[u]]];
}

int hldPos(int u) {
    return id[hld[sta[u]]];
}

int lca(int u, int v) {    
    if (hldDep[u] < hldDep[v]) swap(u, v);
    while (hldDep[u] > hldDep[v]) u = hldPar(u);

    while(sta[u] != sta[v]) {
        u = hldPar(u);
        v = hldPar(v);
    }

    if (dep[u] > dep[v]) swap(u, v);
    return u;
}

int seg[maxn << 2], lazy[maxn << 2];
void down(int id) {
    int x = lazy[id];
    seg[id << 1] += x;
    seg[id << 1 | 1] += x;
    lazy[id << 1] += x;
    lazy[id << 1 | 1] += x;
    lazy[id] = 0;
}

void build(int id, int l, int r) {
    if (l == r) return seg[id] = a[hld[l]], void();
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l or r < u) return;
    if (u <= l and r <= v) {
        seg[id] += val;
        lazy[id] += val;
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

int get(int id, int l, int r, int u, int v) {
    if (v < l or r < u) return 0;
    if (u <= l and r <= v) return seg[id];
    down(id);
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

int get_hld(int u, int v) {
    int k = lca(u, v);
    int ans = 0;

    while(sta[u] != sta[k]) {
        ans += get(1, 1, n, hldPos(u), id[u]);
        u = hldPar(u);
    }

    while(sta[v] != sta[k]) {
        ans += get(1, 1, n, hldPos(v), id[v]);
        v = hldPar(v);
    }

    if (dep[v] < dep[u])
        ans += get(1, 1, n, id[u], id[v]);
    else ans += get(1, 1, n, id[v], id[u]);
    return ans;
}

void update_hld(int u, int v, int val) {
    while(sta[u] != sta[v]) {
        if (hldDep[u] > hldDep[v]) swap(u, v);
        update(1, 1, n, hldPos(v), id[v], val);
        v = hldPar(v);
    }

    if (dep[u] > dep[v]) swap(u, v);
    update(1, 1, n, id[u], id[v], val);
}

void process() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    build_dfs(1, 0);
    build_hld(1, 0, 0);

    FOR(i, 1, k) {
        int x; cin >> x;
        update_hld(1, par[x], 1);
    }

    int ans = 0;
    FOR(i, 1, n) ans += (get_hld(i, i) + a[i]) % 2;
    cout << ans;
}
