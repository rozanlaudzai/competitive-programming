#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*

1 2 3 4
4 1 1 3

1 2 3 4
3 1 1 4

1 2 3 4
1 1 4 3

a a a a a
b b b b b

f[i][j] = reverse [i - j + 1, i]

reverse 3 = reverse 1 + a * b + a * b
reverse 5 = reverse 3 + a * b + a * b

*/

const int mxn = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;

int n, a[5005], b[5005], pre[5005], f[5005][5005];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {

      if (j == 1) {
        f[i][j] = a[i] * b[i];
      } else {
        f[i][j] = f[i - 1][j - 2] + a[i] * b[i - j + 1] + a[i - j + 1] * b[i];
      }
      
    }
  }

  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + a[i] * b[i];
  }

  int ans = pre[n];
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans = max(ans, pre[i - 1] + pre[n] - pre[j] + f[j][j - i + 1]);
    }
  }

  cout << ans << '\n';
  
}
