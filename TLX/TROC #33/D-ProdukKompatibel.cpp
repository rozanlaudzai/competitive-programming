#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int n, ans = 1, x;
  cin >> n;
  while (n--) {
    cin >> x;
    ans *= x;
    ans %= mod;
  }
  cout << ans << '\n';

}
