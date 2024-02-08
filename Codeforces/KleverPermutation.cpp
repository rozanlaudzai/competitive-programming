#include <bits/stdc++.h>
using namespace std;

// 1927E - Klever Permutation

void solve() {
  int n, k;
  cin >> n >> k;

  int l = 1, r = n, st = 1, a[n + 1] = {};
  bool left = true;

  while (l <= r) {
    if (left) {
      for (int i = st; i <= n; i += k) {
        a[i] = l++;
      }
    } else {
      for (int i = st; i <= n; i += k) {
        a[i] = r--;
      }
    }

    ++st;
    left = !left;
  }

  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';

}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  // int x = 1;
  int tc; cin >> tc; while (tc--)
  // {
  // cout << "Case #" << x++ << ": ";
  solve();
  // }

}
