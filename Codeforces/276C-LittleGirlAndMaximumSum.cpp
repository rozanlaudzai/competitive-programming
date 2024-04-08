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

int n, q, l, r, a, t[800005];
priority_queue<int> x, y;

void upd(int v, int tl, int tr, int l, int r, int add) {
  if (l > r) {
    return;
  }

  if (tl == l && tr == r) {
    t[v] += add;
  } else {
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), add);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
  }
}

int get(int v, int tl, int tr, int pos) {
  if (tl == tr) {
    return t[v];
  }

  int tm = (tl + tr) / 2;

  if (pos <= tm) {
    return t[v] + get(v * 2, tl, tm, pos);
  } else {
    return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
  }
}

void solve() {
  cin >> n >> q;
  UFOR (i, 1, n) {
    cin >> a;
    x.push(a);
  }
  
  while (q--) {
    cin >> l >> r;
    upd(1, 1, n, l, r, 1);
  }
  UFOR (i, 1, n) {
    y.push(get(1, 1, n, i));
  }
  int ans = 0;
  while (!y.empty()) {
    ans += y.top() * x.top();
    y.pop();
    x.pop();
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
