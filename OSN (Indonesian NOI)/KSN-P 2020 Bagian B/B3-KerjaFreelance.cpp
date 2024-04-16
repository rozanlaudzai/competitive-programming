#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define db(x) cout << ">>> " << #x << " -> " << x << '\n'
using namespace std;

/*

1 2  3   4   5    6    7    8 9 10
    500 500 2000 2000 2000

*/

int n, x = 0, s[10000], e[10000], p[10000], dp[15001];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> s[i] >> e[i] >> p[i];
    x = max(x, e[i]);
  }
  for(int i = 1; i <= x; ++i)
    for(int j = 0; j < n; ++j)
      if(e[j] <= i)
        dp[i] = max(dp[i], p[j] + dp[s[j] - 1]);
  cout << dp[x] << '\n';

}
