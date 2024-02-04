/*

Final Olimpiade Sains Al Azhar 2024
D. Nasi Goreng

*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 100000;

int n, m, dp[301][301][2];
char ent, a[301][301];

int dfs(int x, int y, int last) { // right: 0, down: 1
  if (x == n && y == m) {
    return 0;
  }
  if (dp[x][y][last] != -1) {
    return dp[x][y][last];
  }

  int res = mx;

  if (y < m && a[x][y + 1] == '.') {
    if (last) {
      res = min(res, dfs(x, y + 1, 0) + 1);
    } else {
      res = min(res, dfs(x, y + 1, 0));
    }
  }
  if (x < n && a[x + 1][y] == '.') {
    if (last) {
      res = min(res, dfs(x + 1, y, 1));
    } else {
      res = min(res, dfs(x + 1, y, 1) + 1);
    }
  }

  return dp[x][y][last] = res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  memset(dp, -1, sizeof dp);

  cin >> n >> m;
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }

  int ans = mx;
  
  if (a[1][2] == '.') {
    ans = dfs(1, 2, 0);
  }
  if (a[2][1] == '.') {
    ans = min(ans, dfs(2, 1, 1));
  }

  cout << ans << '\n';
}
