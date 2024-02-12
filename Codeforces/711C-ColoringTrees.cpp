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
#define em emplace
#define eb emplace_back
#define ef emplace_front
#define lb lower_bound
#define ub upper_bound
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define g3 get<3>
#define g4 get<4>
#define bpc __builtin_popcountll

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define cmin(a, b) a = min(a, b)
#define cmax(a, b) a = max(a, b)
#define mems(arr, a) memset(arr, a, sizeof arr)
#define db(x) cout << ">>> " << #x << " -> " << (x) << '\n'

#define FOR(i, a, n) for (int i = a; i < (n); ++i)
#define UFOR(i, a, n) for (int i = a; i <= (n); ++i)
#define RFOR(i, a, n) for (int i = a; i >= (n); --i)
#define each(i, arr) for (auto &i : arr)

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mod = 1e9 + 7, inf = 1000000000000000001;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double PI = acos(-1);

/*



*/

int n, m, k, c[105], p[105][105], dp[105][105][105];

int f(int id, int cnt, int last) {

  if (!id) {
    if (cnt == k) {
      return 0;
    }
    return inf;
  }
  if (dp[id][cnt][last] != -1) {
    return dp[id][cnt][last];
  }

  int res = inf;

  if (c[id]) {
    if (c[id] == last) {
      res = f(id - 1, cnt, c[id]);
    } else {
      res = f(id - 1, cnt + 1, c[id]);
    }
  } else {
    UFOR (i, 1, m) {
      
      if (i == last) {
        cmin(res, f(id - 1, cnt, i) + p[id][i]);
      } else {
        cmin(res, f(id - 1, cnt + 1, i) + p[id][i]);
      }

    }
  }

  return dp[id][cnt][last] = res;
}

void solve() {
  mems(dp, -1);

  cin >> n >> m >> k;
  UFOR (i, 1, n) {
    cin >> c[i];
  }
  UFOR (i, 1, n) {
    UFOR (j, 1, m) {
      cin >> p[i][j];
    }
  }

  int ans = f(n, 0, 0);
  cout << (ans >= inf ? -1 : ans) << '\n';

}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  // int x = 1;
  // int tc; cin >> tc; while (tc--)
  // {
  // cout << "Case #" << x++ << ": ";
  solve();
  // }

}
