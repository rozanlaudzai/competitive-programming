#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*



*/

const int mxn = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;

struct oof {
  int k, c;
  vector<int> a;
};

int n, m, par[mxn];
oof s[mxn];

int f(int x) {
  return (x == par[x] ? x : par[x] = f(par[x]));
}

void join(int a, int b) {
  a = f(a), b = f(b);

  if (a < b) {
    par[b] = a;
  } else {
    par[a] = b;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
  }
  
  for (int i = 0; i < m; ++i) {
    cin >> s[i].k >> s[i].c;
    s[i].a.resize(s[i].k);
    for (auto &j : s[i].a) {
      cin >> j;
    }
  }
  sort(s, s + m, [&](oof &x, oof &y) {
    return x.c < y.c;
  });

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < s[i].k; ++j) {
      if (f(s[i].a[j - 1]) != f(s[i].a[j])) {
        join(s[i].a[j - 1], s[i].a[j]);
        ans += s[i].c;
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (f(i - 1) != f(i)) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << ans << '\n';
  
}

