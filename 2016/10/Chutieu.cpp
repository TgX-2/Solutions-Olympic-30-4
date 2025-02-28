#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> bigLL;
const ll base = (ll)1e9;
bigLL operator + (const bigLL &a, const bigLL &b) {
   bigLL sum;
   int n = min((int)a.size(), (int)b.size());
   ll mem = 0;
   for(int i = 0; i < n; ++i) {
       ll x = a[i] + b[i] + mem;
       sum.push_back(x % base);
       mem = x / base;
   }
   if(n == (int)a.size()) {
       for(int i = n; i < (int)b.size(); ++i) {
           ll x = b[i] + mem;
           sum.push_back(x % base);
           mem = x / base;
       }
   }
   else {
       for(int i = n; i < (int)a.size(); ++i) {
           ll x = a[i] + mem;
           sum.push_back(x % base);
           mem = x / base;
       }
   }
   if(mem) {
       sum.push_back(mem);
   }
   return sum;
}
bigLL operator * (const bigLL &a, const bigLL &b) {
   bigLL mul((int)a.size() + (int)b.size(), 0);
   for(int i = 0; i < (int)a.size(); ++i) {
       for(int j = 0; j < (int)b.size(); ++j) {
           mul[i + j] += a[i] * b[j];
           mul[i + j + 1] += mul[i + j] / base;
           mul[i + j] %= base;
       }
   }
   mul.push_back(0);
   for(int i = 0; i < (int)mul.size() - 1; ++i) {
       mul[i + 1] += mul[i] / base;
       mul[i] %= base;
   }
   while(mul.back() == 0 && (int)mul.size() > 1) {
       mul.pop_back();
   }
   return mul;
}
bigLL x[501], y[501];
void init() {
   bigLL f3[501], f2[501], f23[501];
   f3[0] = f3[1] = f2[0] = f2[1] = {1};
   f3[2] = f2[2] = {2};
   for(int i = 3; i <= 500; ++i) {
       f3[i] = f3[i - 1] + f3[i - 2] + f3[i - 3];
       f2[i] = f2[i - 1] + f2[i - 2];
       x[i] = f3[i] * f2[i];
   }
   f23[0] = f23[1] = f23[2] = {0};
   for(int i = 3; i <= 500; ++i) {
       f23[i] = f23[i - 1] + f23[i - 2] + f2[i - 3];
       y[i] = f3[i] * f23[i];
   }
}
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   freopen("CHUTIEU.INP", "r", stdin);
   freopen("CHUTIEU.OUT", "w", stdout);
   init();
   int e[9] = {1};
   for(int i = 1; i < 9; ++i) {
       e[i] = e[i - 1] * 10;
   }
   int n, m;
   while(cin >> n >> m) {
       bigLL res = x[n] * y[m];
       cout << res.back();
       for(int i = (int)res.size() - 2; i >= 0; --i) {
           for(int j = 8; j >= 1 && res[i] < e[j]; --j) {
               cout << 0;
           }
           cout << res[i];
       }
       cout << endl;
   }
   return 0;
}
