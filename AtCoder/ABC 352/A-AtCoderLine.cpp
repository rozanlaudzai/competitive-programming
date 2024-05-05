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
  
  int n, x, y, z;
  cin >> n >> x >> y >> z;

  if (x > y) {
    swap(x, y);
  }
  if (x <= z && z <= y) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

}

