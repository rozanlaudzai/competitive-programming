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

greedy way

*/

int n, p, q, x, ans[mxn1];
pair<int, int> a[mxn1];

void solve() {
  cin >> n >> p >> q;
  UFOR (i, 1, n) {
    cin >> a[i].fi;
    a[i].se = i;
  }

  sort(a + 1, a + n + 1);

  int pos = 1;
  priority_queue<pair<int, int>> pq; // range, index: the first that out of range
  UFOR (i, 1, n) {
    while (pos <= n && a[pos].fi - a[i].fi <= p) {
      ++pos;
    }

    pq.em(pos - i, pos);

    while (pq.top().se <= i) { // remove the invalid data
      pq.pop();
    }

    ans[a[i].se] = pq.top().fi;
  }

  while (q--) {
    cin >> x;
    cout << ans[x] << '\n';
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
