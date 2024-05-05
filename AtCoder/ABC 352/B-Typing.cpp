#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*



*/

const int mxn = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string a, b;
  cin >> a >> b;

  int cek = 0;
  for (auto &c : a) {
    for (int i = cek; i < b.size(); ++i) {
      if (b[i] == c) {
        cout << i + 1 << ' ';
        cek = i + 1;
        break;
      }
    }
  }
  cout << '\n';

}

