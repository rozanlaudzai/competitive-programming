/*

OSN 2019
2A. Tempat Wisata

*/

#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    c[i] = a[i];
    d[i] = b[i];
  }
  sort(all(a));
  sort(all(b));

  for (int i = 0; i < n; ++i) {
    cout << (upper_bound(all(a), d[i]) - a.begin()) - (lower_bound(all(b), c[i]) - b.begin()) - 1 << '\n';
  }
}
