#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*

(Explanatation in Bahasa Indonesia)

- for every connected comp, cobain 2 kemungkinan ke satu node saja akan berdampak ke lainnya
- tidak directed
- tidak valid cuz saling menuduh tapi berbeda

*/

const int mxn = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;

bool inva, vis[mxn], sta[mxn];
int n, m, a, b, cnt, cntb;
string c;
vector<pair<int, bool>> adj[mxn]; // node, (0: impos 1: crew)

void dfs(int v, bool s) {
  vis[v] = true;
  ++cnt;
  if (s) {
    ++cntb;
  }
  sta[v] = s;

  for (auto &i : adj[v]) {
    if (vis[i.fi]) { // cek apakah valid

      if (sta[i.fi] != (i.se ? s : !s)) {
        inva = true;
      }
      
    } else { // explore lagi

      dfs(i.fi, (i.se ? s : !s));
      
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    
    cin >> n >> m;

    // init
    inva = false;
    for (int i = 1; i <= n; ++i) {
      vis[i] = sta[i] = false;
      adj[i].clear();
    }
    
    while (m--) {
      cin >> a >> b >> c;

      if (c[0] == 'i') {
        adj[a].emplace_back(b, false);
        adj[b].emplace_back(a, false);
      } else {
        adj[a].emplace_back(b, true);
        adj[b].emplace_back(a, true);
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        cnt = 0, cntb = 0;

        dfs(i, false);
        if (inva) {
          cout << -1 << '\n';
          goto done;
        }

        ans += max(cntb, cnt - cntb);
      }
    }

    cout << ans << '\n';
    
    done: ;
  }

}

