
double leng(const pair<int, int> &a, const pair<int, int> &b)
{
    double x = abs(a.fi - b.fi);
    double y = abs(a.se - b.se);
    return sqrt(x * x + y * y);
}

double heron(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double f(double a, double b, double c)
{
    if (a * a > b * b + c * c or b * b > a * a + c * c)
        return min(a, b);
    return heron(a, b, c) * 2 / c;
}

bool check(const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &tar, const int &r)
{
    double aa = leng(a, tar);
    double bb = leng(b, tar);
    double cc = leng(a, b);
    if (f(aa, bb, cc) <= r)
        return 1;
    return 0;
}

int s, n, d;
const int maxn = 2007;
array<int, 4> a[maxn];
pair<int, int> q[maxn];
bool vis[maxn];
void process()
{
    cin >> s >> n >> d;
    FOR(i, 1, s)
    {
        int x, y, r, val;
        cin >> x >> y >> r >> val;
        a[i] = {x, y, r + d, val};
    }

    FOR(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        q[i] = {x, y};
    }
    q[n + 1] = {0, 0};

    int ans = 0;
    FOR(i, 0, n)
    {
        FOR(j, 1, s) if (!vis[j]) {
            if (check(q[i], q[i + 1], {a[j][0], a[j][1]}, a[j][2])) {
                // cout << i _ j __ ;
                vis[j] = 1;
                ans += a[j][3];
            }
        }
    }
    cout << ans;
}
