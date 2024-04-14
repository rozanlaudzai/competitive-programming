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

=== 1713C - Build Permutation ===

1
0

2
1 0

3
1 0 2

4
0 3 2 1

5
4 3 2 1 0

6
4 3 2 1 0 5
0 5 4 3 2 1
3 2 1 0 5 4
-1

*/

void solve() {
  int n;
  cin >> n;

  int babu, cek = n - 1, a[n] = {};
  bool vis[n] = {};

  RFOR (i, n - 1, 0) {
    UFOR (j, 0, cek) {
      babu = sqrt(i + j);

      if (babu * babu == i + j) {
        a[i] = j;
        vis[i] = true;
        i -= cek - j;
        cek = j - 1;

        break;
      }
    }
  }

  RFOR (i, n - 2, 0) {
    if (!vis[i]) {
      a[i] = a[i + 1] + 1;
    }
    babu = sqrt(a[i] + i);

    if (a[i] >= n || a[i] < 0 || babu * babu != i + a[i]) {
      cout << -1 << '\n';
      return;
    }
  }

  each (i, a) {
    cout << i << ' ';
  }
  cout << '\n';

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
