const int maxn = 1e5 + 7;
int pre[3][maxn], n;
 
int bs1(int u, int v, int st) {
	int l = u, r = v, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
 
		if (pre[0][mid] - pre[0][st - 1] >= 3 or 
			pre[1][mid] - pre[1][st - 1] >= 3 or 
			pre[2][mid] - pre[2][st - 1] >= 3) {
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
	}
	return ans;
}
 
int bs2(int u, int v, int st) {
	int l = u, r = v, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if (pre[0][st] - pre[0][mid - 1] >= 3 or 
			pre[1][st] - pre[1][mid - 1] >= 3 or 
			pre[2][st] - pre[2][mid - 1] >= 3) {
				ans = mid;
				l = mid + 1;
			} else r = mid - 1;
	}
	return ans;
}
 
void process() {
	string s; cin >> s;
	FORSt(i, s) {
		pre[0][i + 1] = pre[0][i];
		pre[1][i + 1] = pre[1][i];
		pre[2][i + 1] = pre[2][i];
		if (s[i] == 'O') pre[0][i + 1]++;
		if (s[i] == 'L') pre[1][i + 1]++;
		if (s[i] == 'P') pre[2][i + 1]++;
	}
 
	n = len(s); s = " " + s;
 
	int ans = 0;
	FOR(i, 1, n - 2) {
		if (pre[0][n] - pre[0][i - 1] >= 3 or
			pre[1][n] - pre[1][i - 1] >= 3 or
			pre[2][n] - pre[2][i - 1] >= 3) {
			int tmp = bs1(i, n, i);
			ans += (n - tmp + 1);
		}
		
	}
	cout << ans;

}
