#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*



*/

const int mxn = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;

bool vis[mxn], big[mxn];
int n, m, q, a, b, c, great[mxn];
vector<int> adj[mxn];

void dfs(int v) {
  vis[v] = true;

  bool indi = true;
  for (auto &i : adj[v]) {
    if (i > v) {
      indi = false;
      ++great[v];
    }

    if (!vis[i]) {
      dfs(i);
    }
  }

  
  big[v] = indi;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  while (m--) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (big[i]) {
      ++ans;
    }
  }

  cin >> q;
  while (q--) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c;

      if (b > c) {
        swap(b, c);
      }
      ++great[b];
      if (big[b]) {
        big[b] = false;
        --ans;
      }

    } else if (a == 2) {
      cin >> b >> c;

      if (b > c) {
        swap(b, c);
      }
      --great[b];
      if (!great[b]) {
        big[b] = true;
        ++ans;
      }
      
    } else {
      cout << ans << '\n';
    }
    
  }

}
