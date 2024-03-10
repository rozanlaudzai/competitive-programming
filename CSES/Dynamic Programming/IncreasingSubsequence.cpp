#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5 + 5, inf = 1e9 + 1;

int n, x, dp[mxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    dp[i] = inf;
  }

  for (int i = 0; i < n; ++i) {
    cin >> x;

    int l = upper_bound(dp, dp + n + 1, x) - dp;
    if (dp[l - 1] < x && x < dp[l]) {
      dp[l] = x;
    }
  }

  for (int i = n; i >= 0; --i) {
    if (dp[i] < inf) {
      cout << i << '\n';
      return 0;
    }
  }

}
