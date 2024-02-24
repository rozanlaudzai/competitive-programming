#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int n, m, x, y;
  cin >> n >> m >> x >> y;
  cout << ((n - x) + (m - y) + (m - y) > 25 ? "LOLOS\n" : "TIDAK LOLOS\n");

}
