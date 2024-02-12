/*

OSN 2019
1A. Mengumpulkan Peserta

*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 2e9;

char babu;
int r, c, cnt = 0, ans = inf;
vector<vector<int>> a;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  cin >> r >> c;
  a.resize(r + 5, vector<int>(c + 5));

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      cin >> babu;
      a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
      if(babu == '1') {
        ++a[i][j];
        ++cnt;
      }
    }
  }

  for (int x = 1; x <= r; ++x) {
    if(cnt % x == 0 && cnt / x <= c) {
      int y = cnt / x;
      for (int i = x; i <= r; ++i) {
        for (int j = y; j <= c; ++j) {
          ans = min(ans, cnt - (a[i][j] - a[i - x][j] - a[i][j - y] + a[i - x][j - y]));
        }
      }
    }
  }

  cout << (ans == inf ? -1 : ans) << '\n';
}
