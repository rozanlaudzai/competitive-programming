#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size(), z[n] = {}, l = 0, r = 0;

  for (int i = 1; i < n; ++i) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }

    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }

  int mx = 0;
  multiset<int>::iterator it;
  multiset<int> ms;

  for (int i = 1; i < n; ++i) {
    ms.insert(z[i]);
  }

  for (int i = n - 1; i; --i) {
    
    it = ms.lower_bound(z[i]);
    ms.erase(it);
    
    if (i + z[i] == n) {

      it = ms.lower_bound(z[i]);

      if (it != ms.end()) {
        mx = z[i];
      }
      
    }
  }

  cout << (mx ? s.substr(n - mx, mx) : "Just a legend") << '\n';
  
}
