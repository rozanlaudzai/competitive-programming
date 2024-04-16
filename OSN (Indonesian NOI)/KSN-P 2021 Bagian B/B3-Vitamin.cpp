// do not use long long, it causes runtime error

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define ins insert
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

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

#define pq(x) priority_queue<x>
#define rpq(x) priority_queue<x, vector<x>, greater<x>>
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<int, int, int, int, int> iiiii;

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mod = 1e9 + 7;
const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1}, dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
const double PI = acos(-1);

// ===============================================================================

int n, m, h[1005], k[1005], d[1005], dp[1005][10005];

int f(int id, int sisa) {
  if(!id) {
    return 0;
  }
  if(dp[id][sisa] != -1) {
    return dp[id][sisa];
  }

  int res = f(id - 1, sisa);

  if(h[id] <= sisa) {
    if(d[id]) {
      cmax(res, f(id - 1, sisa - h[id]) + k[id]);
    }
    else {
      cmax(res, f(id, sisa - h[id]) + k[id]);
    }
  }

  return dp[id][sisa] = res;
}

void solve() {
  mems(dp, -1);

  cin >> n >> m;
  UFOR(i, 1, n) {
    cin >> h[i] >> k[i] >> d[i];
  }

  cout << f(n, m) << '\n';

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
