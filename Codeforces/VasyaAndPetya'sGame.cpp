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

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mod = 1e9 + 7, inf = 1000000000000000001;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double PI = acos(-1);

/*

angka angkanya harus bisa jadi product 2 until n
faktorisasi prima adalah koenjti

*/

void solve() {
  int n;
  cin >> n;

  bool prime[n + 1] = {};
  for (int i = 2; i * i <= n; ++i) {
    if (!prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = true;
      }
    }
  }

  set<int> ans;
  for (int i = 2; i <= n; ++i) {
    if (!prime[i]) {

      int prod = i;

      do {
        ans.ins(prod);
        prod *= i;
      } while (prod <= n);

    }
  }

  cout << sz(ans) << '\n';
  each (i, ans) cout << i << ' ';
  cout << '\n';

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
