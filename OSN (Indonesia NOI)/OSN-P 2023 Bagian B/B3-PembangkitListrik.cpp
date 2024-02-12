/*

OSN-P 2023 Bagian B
B3. Pembangkit Listrik

*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxn = 1e5 + 5;

bool vis[mxn];
int n, m, k, a[mxn], b[mxn];
vector<int> adj[mxn];

int dfs(int x) {
  vis[x] = true;

  int res = a[x];
  
  for (auto &i : adj[x]) {
    if (!vis[i]) {
      res = min(res, dfs(i));
    }
  }

  return res;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  while (k--) {
    int x, y;
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<int> mn;

  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      mn.push_back(dfs(i));
    }
  }

  if (mn.size() > m) {
    cout << -1 << '\n';
    return 0;
  }

  sort(mn.rbegin(), mn.rend());
  sort(b + 1, b + m + 1);

  int ans = 0;
  for (int i = 0; i < mn.size(); ++i) {
    ans += mn[i] * b[i + 1];
  }
  cout << ans << '\n';

}
