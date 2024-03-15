// classic dp knapsack with a linear check for the string

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

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mxn3 = 3e5 + 10, mod = 1e9 + 7, inf = 1000000000000000001;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double PI = acos(-1);

string t;
int n, a, dp[105][105];
vector<vector<string>> s;

int f(int id, int i) {
  if (i == sz(t)) {
    return 0;
  }
  if (id == n) {
    return mod;
  }
  if (dp[id][i] != -1) {
    return dp[id][i];
  }

  int res = f(id + 1, i);

  each (x, s[id]) {
    if (sz(x) <= sz(t) - i) {
      
      bool indi = true;
      FOR (j, 0, sz(x)) {
        if (x[j] != t[i + j]) {
          indi = false;
          break;
        }
      }
      if (indi) {
        cmin(res, f(id + 1, i + sz(x)) + 1);
      }
    }
  }

  return dp[id][i] = res;
}

void solve() {
  mems(dp, -1);
  cin >> t >> n;
  s.resize(n);
  FOR (i, 0, n) {
    cin >> a;
    s[i].resize(a);
    each (j, s[i]) {
      cin >> j;
    }
  }
  int ans = f(0, 0);
  cout << (ans >= mod ? -1 : ans) << '\n';

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
