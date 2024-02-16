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

void solve() {
  int k, q, p;
  char c;
  string s;
  cin >> k >> s;
  int n = sz(s);

  reverse(all(s));
  s = " " + s;

  int dp[n + 1];

  auto upd = [&](int i) {
    if (i * 2 > n) {
      if (s[i] == '?') {
        dp[i] = 2;
      } else {
        dp[i] = 1;
      }
    } else {
      dp[i] = (s[i] != '0' ? dp[i * 2] : 0) + (s[i] != '1' ? dp[i * 2 + 1] : 0);
    }
  };
  
  for (int i = n; i >= 1; --i) {
    upd(i);
  }

  cin >> q;
  while (q--) {
    cin >> p >> c;
    p = n - p + 1;

    s[p] = c;
    
    for (int i = p; i >= 1; i /= 2) {
      upd(i);
    }

    cout << dp[1] << '\n';

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
