#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*



*/

const int mxn = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  pair<int, int> a[n];
  for (auto &i : a) {
    cin >> i.fi >> i.se;
  }
  sort(a, a + n, [&](pair<int, int> &x, pair<int, int> &y) {
    return (x.se - x.fi) < (y.se - y.fi);
  });

  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans += a[i].fi;
  }
  cout << ans + a[n - 1].se << '\n';

}
