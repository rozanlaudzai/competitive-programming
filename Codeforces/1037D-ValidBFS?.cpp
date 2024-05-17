#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int mxn = 2e5 + 10;

bool vis[mxn];
int n, u, v, id[mxn], ans[mxn];
queue<int> q;
vector<int> adj[mxn];

struct Comp {
  bool operator() (int &x, int &y) {
    return id[x] > id[y];
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> v;
    id[v] = i;
  }

  int cur = 1;
  q.push(1);
  vis[1] = true;

  while (!q.empty()) {
    v = q.front();
    q.pop();

    ans[v] = cur++;

    priority_queue<int, vector<int>, Comp> pq;
    
    for (auto &i : adj[v]) {
      if (!vis[i]) {
        vis[i] = true;
        pq.push(i);
      }
    }
    
    while (!pq.empty()) {
      q.push(pq.top());
      pq.pop();
    }

  }

  for (int i = 1; i <= n; ++i) {
    if (ans[i] != id[i]) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";

}
