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
const int dx[] = {0, 1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 0, 1, 0, -1, 1, -1, -1, 1};
const double PI = acos(-1);

/*



*/

bool vis[50][50];
int n, a[50][50], cnt = 1, id = 1;

void dfs(int x, int y) {
  vis[x][y] = true;
  if (x == n / 2 + 1 && y == n / 2 + 1) {
    return;
  }

  a[x][y] = cnt++;

  if (x + dx[id] > n || x + dx[id] < 1 || y + dy[id] > n || y + dy[id] < 1 || vis[x + dx[id]][y + dy[id]]) {
    id = (id % 4) + 1;
  }

  dfs(x + dx[id], y + dy[id]);
}

void solve() {
  cin >> n;

  dfs(1, 1);

  UFOR (i, 1, n) {
    UFOR (j, 1, n) {
      if (i == n / 2 + 1 && j == n / 2 + 1) {
        cout << 'T';
      } else {
        cout << a[i][j];
      }
      cout << ' ';
    }
    cout << '\n';
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
