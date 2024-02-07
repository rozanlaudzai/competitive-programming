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

int n, m, k;
vector<vector<char>> c;
vector<vector<int>> o, x, t;

void solve() {
  
  cin >> n >> m >> k;
  c.resize(n + 5, vector<char>(m + 5));
  o.resize(n + 5, vector<int>(m + 5));
  x.resize(n + 5, vector<int>(m + 5));
  t.resize(n + 5, vector<int>(m + 5));

  UFOR (i, 1, n) {
    UFOR (j, 1, m) {
      cin >> c[i][j];

      o[i][j] += o[i][j - 1] + o[i - 1][j] - o[i - 1][j - 1];
      x[i][j] += x[i][j - 1] + x[i - 1][j] - x[i - 1][j - 1];
      t[i][j] += t[i][j - 1] + t[i - 1][j] - t[i - 1][j - 1];

      if (c[i][j] == 'o') {
        ++o[i][j];
      } else if (c[i][j] == 'x') {
        ++x[i][j];
      } else {
        ++t[i][j];
      }
    }
  }

  int ans = mod;

  UFOR (i, 1, n) {
    UFOR (j, 1, m) {

        // cek kanan
        if (j + k - 1 <= m && x[i][j + k - 1] - x[i - 1][j + k - 1] - x[i][j - 1] + x[i - 1][j - 1] == 0) {
          cmin(ans, t[i][j + k - 1] - t[i - 1][j + k - 1] - t[i][j - 1] + t[i - 1][j - 1]);
        }

        // cek bawah
        if (i + k - 1 <= n && x[i + k - 1][j] - x[i - 1][j] - x[i + k - 1][j - 1] + x[i - 1][j - 1] == 0) {
          cmin(ans, t[i + k - 1][j] - t[i - 1][j] - t[i + k - 1][j - 1] + t[i - 1][j - 1]);
        }

    }
  }

  cout << (ans == mod ? -1 : ans) << '\n';

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
