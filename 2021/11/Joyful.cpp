struct Event {
	int x, y;
	int y1, y2;
	int typ;

	Event(int x, int typ, int y) : x(x), typ(typ), y(y) {}
	Event(int x, int typ, int y1, int y2) : x(x), typ(typ), y1(y1), y2(y2) {}

	bool operator<(const Event &other) const {
		return (x != other.x ? x < other.x : typ < other.typ);
	}
};
vector<int> comp;
vector<Event> event;

struct Fenwick {
	vector<int> bit;
	int n;

	Fenwick(int n) : n(n) {
		bit.resize(n + 7, 0);
	}

	void update(int pos, int val) {
		for(; pos <= n; pos += pos & -pos) 
			bit[pos] += val;
	}

	int get(int pos) {
		int ans = 0;
		for(; pos > 0; pos -= pos & -pos) 
			ans += bit[pos];
		return ans;
	}

	int getRange(int l, int r) {
		return get(r) - get(l - 1);
	}
};

void process() {
	int n; cin >> n;

	FOR(i, 1, n) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);

		if (y1 == y2) {
			event.pb(Event(x1, 0, y1));
			event.pb(Event(x2, 2, y1));
			comp.pb(y1);
		} else {
			event.pb(Event(x1, 1, y1, y2));
			comp.pb(y1);
			comp.pb(y2);
		}
	}

	sort(all(comp));
	comp.erase(unique(all(comp)), comp.end());

	unordered_map<int, int> yy;
	FOR(i, 0, len(comp) - 1)
		yy[comp[i]] = i + 1;

	sort(all(event));
	Fenwick ft(len(comp));
	int ans = 0;

	for(const Event &val : event) {
		if (val.typ == 0) {
			int pos = yy[val.y];
			ft.update(pos, 1);
		} else if (val.typ == 2) {
			int pos = yy[val.y];
			ft.update(pos, -1);
		} else {
			int y1 = val.y1, y2 = val.y2;
			int l = lower_bound(all(comp), y1) - comp.begin();
			int r = upper_bound(all(comp), y2) - comp.begin();
			if (l >= r) continue;

			ans += ft.getRange(l + 1, r);
		}
	}

	cout << ans;
}
