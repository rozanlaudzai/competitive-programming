#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define ins insert
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define bpc __builtin_popcountll

#define g0(tup) get<0>(tup)
#define g1(tup) get<1>(tup)
#define g2(tup) get<2>(tup)
#define g3(tup) get<3>(tup)
#define g4(tup) get<4>(tup)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define cmin(a, b) a = min(a, b)
#define cmax(a, b) a = max(a, b)
#define mems(arr, a) memset(arr, a, sizeof arr)
#define db(x) cout << ">>> " << #x << " -> " << x << '\n'

#define FOR(i, a, n) for(int i = a; i < n; ++i)
#define UFOR(i, a, n) for(int i = a; i <= n; ++i)
#define RFOR(i, a, n) for(int i = a; i >= n; --i)
#define each(i, arr) for(auto &i : arr)

#define v(x) vector<x>
#define pq(x) priority_queue<x>
#define rpq(x) priority_queue<x, vector<x>, greater<x>>
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<int, int, int, int, int> iiiii;

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mod = 1e9 + 7;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double PI = acos(-1);

/*

strategi mundur: mundur sekali maju dua kali

*/

int n, a[mxn1], dp[mxn1];

int f(int id) {
  if(id == n) {
    return 0;
  }
  if(dp[id] != -1) {
    return dp[id];
  }

  int res = f(id + 1) + (a[id] - a[id + 1]) * (a[id] - a[id + 1]);
  if(id > 1) {
    cmin(res, f(id + 1) + (a[id] - a[id - 1]) * (a[id] - a[id - 1]) + 3ll * (a[id - 1] - a[id + 1]) * (a[id - 1] - a[id + 1]));
  }
  if(id < n - 1) {
    cmin(res, f(id + 2) + 3ll * (a[id] - a[id + 2]) * (a[id] - a[id + 2]));
  }

  return dp[id] = res;

}

void solve() {
  mems(dp, -1);
  cin >> n;
  UFOR(i, 1, n) {
    cin >> a[i];
  }

  cout << f(1) << '\n';

}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  // int x = 1;
  // int tc; cin >> tc; while(tc--)
  // {
  // cout << "Case #" << x++ << ": ";
  solve();
  // }

}
