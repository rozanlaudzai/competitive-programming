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

/*



*/

int n, m, par[mxn2];
bool indi, vis[mxn2], done[mxn2];
vector<int> adj[mxn2];

int find(int x) {
  return (x == par[x] ? x : par[x] = find(par[x]));
}

void join(int a, int b) {
  a = find(a), b = find(b);
  if (a < b) {
    par[b] = a;
  } else {
    par[a] = b;
  }
}

void dfs(int v) {
  if (sz(adj[v]) != 2) {
    indi = false;
  }
  if (!indi) {
    return;
  }
  vis[v] = true;

  each (i, adj[v]) {
    if (!vis[i]) {
      dfs(i);
    }
  }
}

void solve() {
  cin >> n >> m;
  UFOR (i, 1, n) {
    par[i] = i;
  }
  int x, y;
  while (m--) {
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
    join(x, y);
  }

  int ans = 0;
  UFOR (i, 1, n) {

    if (!done[find(i)]) {
      done[find(i)] = true;

      indi = true;
      dfs(find(i));
      if (indi) {
        ++ans;
      }
    }
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
