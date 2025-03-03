const int maxn = 5e5 + 7;
int n, q, a[maxn], cntSnail[maxn];
bool b[maxn];
int nxt[maxn], id[maxn];

bool cmp(const int &l, const int &r) {
	return a[l] < a[r];
}

int bs(const int &u, const int &v, const int &tar) {
	int l = u, r = v, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if (a[id[mid]] >= tar) {
			ans = id[mid];
			r = mid - 1;
		} else l = mid + 1; 
	}
	return ans;
}

int st[maxn][30], val[maxn][30];
void build() {
	FOR(j, 1, 18) FOR(i, 1, n) {
		st[i][j] = st[st[i][j - 1]][j - 1];
		val[i][j] = val[i][j - 1] + val[st[i][j - 1]][j - 1];
		if (!st[i][j]) st[i][j] = n + 1;
	}
}

int get(int l, const int &r) {
	int ans = 0;
	FORD(i, 18, 0) if (cntSnail[r] - cntSnail[st[l][i] - 1] >= 1) {
		ans += val[l][i];
		l = st[l][i];
	}
	if (a[r] >= a[l - 1] and cntSnail[r] - cntSnail[l - 1] == 1) ans++;
	return ans;
}

void process() {
	cin >> n >> q;
	FOR(i, 1, n) {
		char x; cin >> x;
		b[i] = (x == '1');
		cntSnail[i] = cntSnail[i - 1] + b[i];
	}

	FOR(i, 1, n) {
		int x; cin >> x;
		a[i] = a[i - 1] + x;
	}

	FOR(i, 1, n) id[i] = i;
	int sum = 0, maxSum = 0;
	nxt[n + 1] = n + 1;

	FORD(i, n, 1) {
		nxt[i] = nxt[i + 1];
		if (b[i] == 1) {
			sum = 0;
			maxSum = llongmin;
		}

		sum += (a[i] - a[i - 1]);
		if (sum >= maxSum) {
			nxt[i] = i;
			maxSum = sum;
		}
	}

	int chose1 = n + 1, chose2 = n;
	FORD(i, n, 1) {
		if (b[i] == 1) {
			chose2 = chose1 - 1;
			chose1 = i;
			sort(id + chose1, id + chose2 + 1, cmp);
		} 
		if (chose1 <= n) {
			int pos = bs(chose1, chose2, a[i - 1]);
			if (pos != -1) {
				st[i][0] = pos + 1;
				val[i][0] = 1;
			} else st[i][0] = nxt[chose1 + 1];
		}
	}

	build();
	while(q--) {
		int l, r; cin >> l >> r;
		cout << get(l, r) __ ;
	}
}
