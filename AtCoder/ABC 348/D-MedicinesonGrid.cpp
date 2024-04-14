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

dijkstra

*/

bool vis[205][205];
int n, m, val, x, y, stx, sty, ttx, tty, e[205][205], d[205][205];
char c[205][205];

typedef tuple<int, int, int> iii;

void solve() {

  cin >> n >> m;
  UFOR (i, 1, n) {
    UFOR (j, 1, m) {
      cin >> c[i][j];
      if (c[i][j] == 'S') {
        stx = i, sty = j;
      } else if (c[i][j] == 'T') {
        ttx = i, tty = j;
      }
    }
  }
  cin >> val;
  while (val--) {
    cin >> x >> y >> e[x][y];
  }

  priority_queue<iii, vector<iii>, greater<iii>> pq;
  mems(d, 0x2f);
  d[stx][sty] = 0;
  vis[stx][sty] = true;
  pq.em(d[stx][sty], stx, sty);

  while (!pq.empty()) {
    val = g0(pq.top()), x = g1(pq.top()), y = g2(pq.top());
    pq.pop();
    if (d[x][y] < val) {
      continue;
    }
    vis[x][y] = true;

    if (-e[x][y] < d[x][y]) {
      d[x][y] = -e[x][y];
    }

    FOR (i, 0, 4) {
      stx = x + dx[i], sty = y + dy[i];

      if (d[x][y] < 0 && stx >= 1 && stx <= n && sty >= 1 && sty <= m && c[stx][sty] != '#' &&  d[stx][sty] > d[x][y] + 1LL) {
        d[stx][sty] = d[x][y] + 1LL;
        pq.em(d[stx][sty], stx, sty);
      }
    }
  }
  cout << (d[ttx][tty] <= 0 && vis[ttx][tty] ? "Yes\n" : "No\n");

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
