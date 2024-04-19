#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
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
const ld PI = acos(-1);

/*



*/

int n, ans = 1, a[mxn2], par[mxn2], cnt[mxn2];

int find(int x) {
  return (x == par[x] ? x : par[x] = find(par[x]));
}

void join(int x, int y) {
  x = find(x), y = find(y);

  if (x < y) {
    cnt[x] += cnt[y];
    par[y] = x;
  } else if (x > y) {
    cnt[y] += cnt[x];
    par[x] = y;
  }
}

void solve() {
  cin >> n;
  UFOR (i, 1, n) {
    cin >> a[i];
    par[i] = i;
    cnt[i] = 1;
  }

  UFOR (i, 2, n) {
    if (a[i - 1] < a[i]) {
      join(i - 1, i);
      cmax(ans, cnt[find(i)]);
    }
  }

  FOR (i, 2, n) {
    if (a[i - 1] < a[i + 1] && find(i - 1) != find(i + 1)) {
      if (find(i) == find(i - 1) || find(i) == find(i + 1)) {
        cmax(ans, cnt[find(i - 1)] + cnt[find(i + 1)] - 1);
      } else {
        cmax(ans, cnt[find(i - 1)] + cnt[find(i + 1)]);
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
