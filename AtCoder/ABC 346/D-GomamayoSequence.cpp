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



*/

int n, c[mxn2];
string s;

void solve() {
  cin >> n >> s;
  s = " " + s;
  UFOR (i, 1, n) {
    cin >> c[i];
  }

  // precompute start with 0 1
  int zo[n + 5] = {};

  bool indi = false;
  UFOR (i, 1, n) {
    zo[i] = zo[i - 1];

    if (s[i] != (indi ? '1' : '0')) {
      zo[i] += c[i];
    }

    indi = !indi;
  }

  // start with 1 0
  int oz[n + 5] = {};

  indi = true;
  UFOR (i, 1, n) {
    oz[i] = oz[i - 1];

    if (s[i] != (indi ? '1' : '0')) {
      oz[i] += c[i];
    }

    indi = !indi;
  }

  int ans = inf;
  UFOR (i, 2, n) {
    // 0 0
    int babu = (i % 2 ? oz[i - 1] : zo[i - 1]) + (i % 2 ? zo[n] - zo[i - 1] : oz[n] - oz[i - 1]);
    cmin(ans, babu);

    // 1 1
    babu = (i % 2 ? zo[i - 1] : oz[i - 1]) + (i % 2 ? oz[n] - oz[i - 1] : zo[n] - zo[i - 1]);
    cmin(ans, babu);
  }

  cout << ans << '\n';
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
