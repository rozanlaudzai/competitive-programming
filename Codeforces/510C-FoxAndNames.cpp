#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*

- toposort
- sensitive case: all characters are the same but differ in length

*/

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string s[n];
  for (auto &i : s) {
    cin >> i;
  }

  int cnt[123] = {};
  vector<int> adj[123];

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {

      bool same = true;
      
      for (int k = 0; k < min(s[i].size(), s[j].size()); ++k) {
        if (s[i][k] != s[j][k]) {
          same = false;
          
          ++cnt[s[i][k]];
          adj[s[j][k]].push_back(s[i][k]);
          break;
        }
      }

      if (same && s[i].size() > s[j].size()) {
        cout << "Impossible\n";
        return 0;
      }
    }
  }

  queue<char> q;
  for (char i = 'a'; i <= 'z'; ++i) {
    if (!cnt[i]) {
      q.push(i);
    }
  }

  string ans;
  while (!q.empty()) {
    char x = q.front();
    q.pop();

    ans += x;
    
    for (auto &i : adj[x]) {
      if (!--cnt[i]) {
        q.push(i);
      }
    }
  }

  for (char i = 'a'; i <= 'z'; ++i) {
    if (cnt[i]) {
      cout << "Impossible\n";
      return 0;
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  
}
