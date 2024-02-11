// 710E - Generate a String

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

  int n, x, y;
  cin >> n >> x >> y;
  int dp[n + 1];

  dp[1] = x;
  for (int i = 2; i <= n; ++i) {
    if (i & 1) {
      dp[i] = min(dp[(i + 1) / 2] + x + y, dp[i - 1] + x);
    } else {
      dp[i] = min(dp[i / 2] + y, dp[i - 1] + x);
    }
  }
  cout << dp[n] << '\n';

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
