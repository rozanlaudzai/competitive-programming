// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxn = 1e5 + 5, mod = 1e9 + 7;

int n, m, a[mxn], dp[mxn][105];

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  // base case
  if (a[1]) {
    dp[1][a[1]] = 1;
  } else {
    for (int j = 1; j <= m; ++j) {
      dp[1][j] = 1;
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (a[i]) {
      dp[i][a[i]] = dp[i - 1][a[i]] + dp[i - 1][a[i] - 1] + dp[i - 1][a[i] + 1];
      dp[i][a[i]] %= mod;
    } else {

      for (int j = 1; j <= m; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
        dp[i][j] %= mod;
      }

    }
  }

  int ans = 0;
  for (int j = 1; j <= m; ++j) {
    ans += dp[n][j];
    ans %= mod;
  }

  cout << ans << '\n';

}
