#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*

-011???0111
^ ^^

cnt = 2
lastid = 

-011???0111

last = 1
lastid = 3
i = 7
genap = harus sama

*/

const int mxn = 2e5 + 5, mod = 1e9 + 7, inf = 2e18;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) {

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    int ans = n, cnt = 0, lastcnt = 0, lastid = 0;
    char last = '.';

    for (int i = 1; i <= n; ++i) {

      if (s[i] == '?') {
        ++cnt;
      } else {

        if ((lastid - i) % 2) { // harus beda
          if (last == s[i]) {
            
            ans += lastcnt * (lastcnt - 1) / 2LL + lastcnt * (cnt - lastcnt);

            cnt -= lastcnt - 1;
          } else {
            ++cnt;
          }
        } else { // harus sama
          if (last == s[i]) {
            ++cnt;
          } else {

            ans += lastcnt * (lastcnt - 1) / 2LL + lastcnt * (cnt - lastcnt);

            cnt -= lastcnt - 1;
          }
        }

        lastcnt = cnt;
        last = s[i];
        lastid = i;
      }

    }

    cout << ans + cnt * (cnt - 1) / 2LL << '\n';

  }

}
