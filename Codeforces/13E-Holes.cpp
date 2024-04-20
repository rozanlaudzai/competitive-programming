/*

13E - Holes

divide into sqrt(n) parts
dp only works on 2 indexes with the same part but not different parts

*/

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

int n, q, t, x, y, s, a[mxn1], cnt[mxn1], nex[mxn1], last[mxn1];

void solve() {
  cin >> n >> q;
  UFOR (i, 1, n) {
    cin >> a[i];
    cnt[i] = 1;
    last[i] = i;
  }

  s = sqrt(n);

  // UFOR (i, 1, n) {
  //   cout << i / s << ' ';
  // }
  // cout << '\n';

  RFOR (i, n, 1) {
    if (i + a[i] <= n && i / s == (i + a[i]) / s) {
      nex[i] = nex[i + a[i]];
      last[i] = last[i + a[i]];
      cnt[i] += cnt[i + a[i]];
    } else {
      nex[i] = i + a[i];
    }
  }

  while (q--) {
    cin >> t;
    if (t) {
      cin >> x;

      int jmp = 0;

      while (true) {
        jmp += cnt[x];

        if (nex[x] > n) {
          break;
        }

        x = nex[x];
      }

      cout << last[x] << ' ' << jmp << '\n';

    } else {
      cin >> x >> y;
      a[x] = y;

      y = x / s;

      for (int i = x; i && i / s == y; --i) {
        if (i + a[i] <= n && i / s == (i + a[i]) / s) {
          nex[i] = nex[i + a[i]];
          last[i] = last[i + a[i]];
          cnt[i] = cnt[i + a[i]] + 1;
        } else {
          nex[i] = i + a[i];
          last[i] = i;
          cnt[i] = 1;
        }
      }

    }
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
