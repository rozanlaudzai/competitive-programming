#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*



*/

const int mxn = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;

int n, a[mxn], dp[mxn];

int f(int id) {
  if (id == n + 1) {
    return 0;
  }
  if (dp[id] != -1) {
    return dp[id];
  }

  int res = f(id + 1) + 1;
  if (id + a[id] <= n) {
    res = min(res, f(id + a[id] + 1));
  }
  return dp[id] = res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      dp[i] = -1;
    }

    cout << f(1) << '\n';
  }
 
}
