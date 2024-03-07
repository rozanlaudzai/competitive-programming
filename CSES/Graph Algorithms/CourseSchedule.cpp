#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, fir[100005];
vector<int> adj[100005];

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
    ++fir[a];
    adj[b].push_back(a);
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (!fir[i]) {
      q.push(i);
    }
  }

  stack<int> ans;

  while (!q.empty()) {
    a = q.front();
    q.pop();

    ans.push(a);

    for (auto &i : adj[a]) {
      --fir[i];
      if (!fir[i]) {
        q.push(i);
      }
    }
  }

  if (ans.size() == n) {
    while (!ans.empty()) {
      cout << ans.top() << ' ';
      ans.pop();
    }
  } else {
    cout << "IMPOSSIBLE\n";
  }

}
