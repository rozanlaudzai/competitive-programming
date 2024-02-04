/*

Final Olimpiade Al Azhar 2024
E. Mengamati Semut

*/

#include <stdio.h>
#include <utility>
#include <vector>
#include <cmath>
using std::pair;
using std::vector;

const int mxn = 30001;
bool vis[mxn];
int a, b, c, n, m, res[mxn];
vector<pair<int, int>> adj[mxn];

void dfs(int x) {
  vis[x] = true;
  for (pair<int, int> &i : adj[x]) {
    if (!vis[i.first]) {
      res[i.first] = res[x] + i.second;
      dfs(i.first);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);

  while (m--) {
    scanf("%d%d%d", &a, &b, &c);
    adj[a].emplace_back(b, c);
    adj[b].emplace_back(a, -c);
  }

  dfs(1);

  printf("%d\n", (vis[n] ? abs(res[n]) : -1));

}
