#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 5;

int n, a[mxn];
bool dp[105][mxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  // base case
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = true;
  }

  set<int> ans;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < mxn; ++j) {
      if (a[i] <= j) {
        dp[i][j] = dp[i - 1][j - a[i]];
        if (dp[i][j]) {
          ans.insert(j);
        }
      }

      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }

  cout << ans.size() << '\n';
  for (auto &i : ans) {
    cout << i << ' ';
  }
  cout << '\n';

}
