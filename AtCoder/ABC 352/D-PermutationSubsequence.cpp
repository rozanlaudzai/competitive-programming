#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*

available: [1, n - k + 1]
implementation: segtree

*/

const int mxn = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;

int n, k, a[mxn], id[mxn], t[800005], tmn[800005];

void bui(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = id[tl];
  } else {
    int tm = (tl + tr) / 2;
    bui(v * 2, tl, tm);
    bui(v * 2 + 1, tm + 1, tr);
    
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}

int que(int v, int tl, int tr, int l, int r) {

  if (l > r) {
    return 0;
  }
  if (l == tl && r == tr) {
    return t[v];
  }

  int tm = (tl + tr) / 2;
  return max(
    que(v * 2, tl, tm, l, min(r, tm)),
    que(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
  );

}
void buimn(int v, int tl, int tr) {
  if (tl == tr) {
    tmn[v] = id[tl];
  } else {
    int tm = (tl + tr) / 2;
    buimn(v * 2, tl, tm);
    buimn(v * 2 + 1, tm + 1, tr);
    
    tmn[v] = min(tmn[v * 2], tmn[v * 2 + 1]);
  }
}

int quemn(int v, int tl, int tr, int l, int r) {

  if (l > r) {
    return inf;
  }
  if (l == tl && r == tr) {
    return tmn[v];
  }

  int tm = (tl + tr) / 2;
  return min(
    quemn(v * 2, tl, tm, l, min(r, tm)),
    quemn(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
  );

}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    id[a[i]] = i;
  }
  if (k == 1) {
    cout << 0 << '\n';
    return 0;
  }

  int ans = inf;
  bui(1, 1, n);
  buimn(1, 1, n);

  for (int i = 1; i <= n - k + 1; ++i) {
    ans = min(ans, que(1, 1, n, i, i + k - 1) - quemn(1, 1, n, i, i + k - 1));
    // if (ans == 1) {
    //   cout << i << ' ' << i + k - 1 << '\n';
    // }
  }

  cout << ans << '\n';
}

