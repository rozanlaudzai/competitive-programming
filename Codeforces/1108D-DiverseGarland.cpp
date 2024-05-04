#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*

RBGRRBRGG
RBGRGBRBG

RGRGRGRGRGRGRG

RBGRRRB

RBGRRGGGG
RGBRRGRGG

- prioritize all that the same: RRR, GGG, BBB
- change the remaining

*/

const int mxn = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;

int n;
char s[mxn];
const char oof[] = {'R', 'G', 'B'};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }

  int ans = 0;
  for (int i = 2; i < n; ++i) {
    if (s[i] == s[i - 1] && s[i] == s[i + 1]) {
      for (auto &c : oof) {
        if (c != s[i]) {
          s[i] = c;
          break;
        }
      }
      ++ans;
    }
    
  }
  for (int i = 1; i <= n; ++i) {
    if (s[i] == s[i - 1] || s[i] == s[i + 1]) {
      for (auto &c : oof) {
        if (c != s[i - 1] && c != s[i + 1]) {
          s[i] = c;
          break;
        }
      }

      ++ans;
    }
  }
  
  cout << ans << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << s[i];
  }
  cout << '\n';

}
