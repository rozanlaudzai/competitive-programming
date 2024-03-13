// dp[i][j] = a[i][j] + minimum_dp_from_(j - d)_until_(j - 1)
// use segtree for the find the minium_dp

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

int n, m, k, d, a[105][mxn2], t[400005];

int que(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return inf;
  }
  if (l == tl && r == tr) {
    return t[v];
  }

  int tm = (tl + tr) / 2;
  return min(
    que(v * 2, tl, tm, l, min(r, tm)),
    que(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
  );
}

void upd(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = val;
    
  } else {

    int tm = (tl + tr) / 2;

    if (tm >= pos) {
      upd(v * 2, tl, tm, pos, val);
    }
    else {
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    }

    t[v] = min(t[v * 2], t[v * 2 + 1]);

  }
}

void solve() {
  cin >> n >> m >> k >> d, ++d;
  UFOR (i, 1, n) {
    UFOR (j, 1, m) {
      cin >> a[i][j], ++a[i][j];
    }
  }

  UFOR (i, 1, n) {
    upd(1, 1, m, 1, 1);
    UFOR (j, 2, m) {
      a[i][j] += que(1, 1, m, max(1ll, j - d), j - 1);
      upd(1, 1, m, j, a[i][j]);
    }
  }

  int ans = inf;
  UFOR (i, 1, n) {
    a[i][m] += a[i - 1][m];
    if (k <= i) {
      cmin(ans, a[i][m] - a[i - k][m]);
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
