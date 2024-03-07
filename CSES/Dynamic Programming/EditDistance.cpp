// https://cses.fi/problemset/result/8658014/

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size(), dp[n + 1][m + 1];
  a = " " + a;
  b = " " + b;

  // base case
  memset(dp, 0x2f, sizeof dp); // assume inf value
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = i;
  }
  for (int j = 1; j <= m; ++j) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {

      if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];

      else dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
      
    }
  }

  cout << dp[n][m] << '\n';

}
