/*

using dsu to find the MEX
only a cut to 2 parts

*/

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

int par[mxn2];

int find(int x) {
  return (x == par[x] ? x : par[x] = find(par[x]));
}

void join(int a, int b) {
  a = find(a), b = find(b);
  if (a < b) {
    par[a] = b;
  } else {
    par[b] = a;
  }
}

void solve() {
  
  int n;
  cin >> n;

  UFOR (i, 0, n) {
    par[i] = i;
  }

  int mn = 0, a[n];
  bool vis[n + 1] = {};

  each (i, a) {
    cin >> i;
    vis[i] = true;
    join(i, i + 1);
    if (i == mn) {
      mn = find(i + 1);
      if (vis[mn]) {
        ++mn;
      }
    }
  }

  mems(vis, false);
  UFOR (i, 0, n) {
    par[i] = i;
  }
  vector<pair<int, int>> ans;
  int l = 0, r = -1, cur = 0;
  FOR (i, 0, n) {
    ++r;

    vis[a[i]] = true;
    join(a[i], a[i] + 1);

    if (a[i] == cur) {
      cur = find(a[i] + 1);
      if (vis[cur]) {
        ++cur;
      }
    }

    if (cur == mn) {
      ans.eb(l, r);
      break;
    }

  }

  mems(vis, false);
  UFOR (i, 0, n) {
    par[i] = i;
  }
  cur = 0;
  l = r + 1;
  FOR (i, r + 1, n) {
    ++r;

    vis[a[i]] = true;
    join(a[i], a[i] + 1);

    if (a[i] == cur) {
      cur = find(a[i] + 1);
      if (vis[cur]) {
        ++cur;
      }
    }

  }
  if (cur == mn) {
    cout << 2 << '\n';
    cout << ans[0].fi + 1 << ' ' << ans[0].se + 1 << '\n';
    cout << l +1 << ' ' << r + 1 << '\n';
  } else {
    cout << -1 << '\n';
  }

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
