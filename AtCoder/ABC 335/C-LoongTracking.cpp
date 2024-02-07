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
#define bpc __builtin_popcountll
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define g3 get<3>
#define g4 get<4>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define cmin(a, b) a = min(a, b)
#define cmax(a, b) a = max(a, b)
#define mems(arr, a) memset(arr, a, sizeof arr)
#define db(x) cout << ">>> " << #x << " -> " << x << '\n'

#define FOR(i, a, n) for (int i = a; i < n; ++i)
#define UFOR(i, a, n) for (int i = a; i <= n; ++i)
#define RFOR(i, a, n) for (int i = a; i >= n; --i)
#define each(i, arr) for (auto &i : arr)

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mod = 1e9 + 7;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double PI = acos(-1);

/*



*/

int n, q, babu;

void solve() {
  cin >> n >> q;
  deque<pair<int, int>> co;
  UFOR (i, 1, n) {
    co.pb(mp(i, 0));
  }
  
  int x;
  char c;

  while(q--) {
    cin >> babu;

    if (babu == 1) {
      cin >> c;
      if (c == 'R') {
        co.pf(mp(co[0].fi + 1, co[0].se));
      } else if (c == 'L') {
        co.pf(mp(co[0].fi - 1, co[0].se));
      } else if (c == 'U') {
        co.pf(mp(co[0].fi, co[0].se + 1));
      } else {
        co.pf(mp(co[0].fi, co[0].se - 1));
      }
    } else {
      cin >> x;
      cout << co[x - 1].fi << ' ' << co[x - 1].se << '\n';
    }
  }
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
