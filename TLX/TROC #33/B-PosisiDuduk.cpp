#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int m, a, b;
  cin >> m >> a >> b;

  int mx = min(a, b), mn = (a % 2 && b % 2);
  if(m + m > a + b) {
    mn = 0;
  }

  cout << mn << ' ' << mx << '\n';

}
