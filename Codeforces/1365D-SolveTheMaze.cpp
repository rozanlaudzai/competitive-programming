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

bool vis[55][55];
char c[55][55];
int n, m;

void dfs(int x, int y) {
  vis[x][y] = true;

  FOR (i, 0, 4) {
    int tx = x + dx[i], ty = y + dy[i];
    if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && c[tx][ty] != '#' && !vis[tx][ty]) {
      dfs(tx, ty);
    }
  }

}

void solve() {
  mems(vis, false);
  cin >> n >> m;

  vector<pair<int, int>> g, b;

  UFOR (i, 1, n) {
    UFOR (j, 1, m) {
      cin >> c[i][j];
      if (c[i][j] == 'G') {
        g.eb(i, j);
      } else if (c[i][j] == 'B') {
        b.eb(i, j);
      }
    }
  }

  dfs(n, m);

  each (i, b) {
    if (vis[i.fi][i.se]) {
      FOR (j, 0, 4) {
        int tx = i.fi + dx[j], ty = i.se + dy[j];
        if (c[tx][ty] == '.') {
          c[tx][ty] = '#';
        }
      }
    }
  }

  mems(vis, false);

  if (c[n][m] == '.') {
    dfs(n, m);
  }

  each (i, b) {
    if (vis[i.fi][i.se]) {
      db("babi");
      cout << "No\n";
      return;
    }
  }
  each (i, g) {
    if (!vis[i.fi][i.se]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";

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
