int n,m,s,t;
vector<pair<int, int> g[10007];

int d[10007];
void sol(){
    FOR(i,1,n) d[i] = intmin;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({intmax, s});
	while (!q.empty()){
        auto _x = q.top(); q.pop();
        int u = _x.se, cost = _x.fi;
        if (cost<d[u]) continue;
        if (u==t) continue;
 		for(auto x : g[u]){
            int v = x.fi, w = x.se;
			if (min(w, cost) > d[v]){
				d[v] = min(w, cost);
				q.push({d[v], v});
			}
		}
	}
	cout << d[t];
}


void process() {
    cin >> n >> m >> s >> t;
    FOR(i,1,m) {
        int u,v,w; cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }   
    sol();
}
