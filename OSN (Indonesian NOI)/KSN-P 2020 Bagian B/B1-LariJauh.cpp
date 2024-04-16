#include <bits/stdc++.h>
using namespace std;

int n, k, a[100001];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];

  while (k > 0) {
    int ans = 0, b;
    cin >> b;

    for (int i = 1; i <= n; i++) {
      
      if (b < a[i]) break;
      
      b -= a[i];
      ++ans;
    }

    cout << ans << endl;
    --k;
  }

}
