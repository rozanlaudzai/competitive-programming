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
#define db(x) cerr << ">>> " << #x << " -> " << (x) << '\n'

#define FOR(i, a, n) for (int i = a; i < (n); ++i)
#define UFOR(i, a, n) for (int i = a; i <= (n); ++i)
#define RFOR(i, a, n) for (int i = a; i >= (n); --i)
#define each(i, arr) for (auto &i : arr)

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mxn3 = 3e5 + 10, mod = 1e9 + 7, inf = 1000000000000000001;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double PI = acos(-1);

/*

- the values of odd indices are the same and the values of even indices are the same and even length
- all values are the same

*/

void solve() {
  string s;
  cin >> s;
  int n = sz(s), ans = 0, cnt[26] = {};
  each (i, s) {
    i -= '0';
    cmax(ans, ++cnt[i]);
  }
  s = " " + s;

  ans = n - ans;

  FOR (a, 0, 26) {
    FOR (b, 0, 26) {
      if (a == b) {
        continue;
      }
      bool indi = false;
      int len = 0;
      each (i, s) {
        if (indi) {
          if (i == b) {
            ++len;
            indi = !indi;
          }
        } else {
          if (i == a) {
            ++len;
            indi = !indi;
          }
        }
      }

      cmin(ans, n - len + len % 2);

    }
  }
  cout << ans << '\n';

}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  // int x = 1;
  int tc; cin >> tc; while (tc--)
  // {
  // cout << "Case #" << x++ << ": ";
  solve();
  // }

}
