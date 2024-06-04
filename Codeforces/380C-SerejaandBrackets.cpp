
// Sereja and Brackets

#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;

  struct oof {
    int tot = 0, op = 0, cl = 0;
  };

  vector<oof> t(n * 4 + 5);

  function<void(int, int, int)> bui = [&](int v, int tl, int tr) {
    if (tl == tr) {
      if (s[tl] == '(') {
        t[v].op = 1;
      } else {
        t[v].cl = 1;
      }
    } else {
      int tm = (tl + tr) / 2;
      bui(v * 2, tl, tm);
      bui(v * 2 + 1, tm + 1, tr);

      t[v].op = t[v * 2].op + t[v * 2 + 1].op;
      t[v].cl = t[v * 2].cl + t[v * 2 + 1].cl;
      t[v].tot = t[v * 2].tot + t[v * 2 + 1].tot + min(t[v * 2].op - t[v * 2].tot / 2, t[v * 2 + 1].cl - t[v * 2 + 1].tot / 2) * 2;
    }
  };

  oof emp;
  function<oof(int, int, int, int, int)> que = [&](int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return emp;
    }
    if (tl == l && tr == r) {
      return t[v];
    }

    int tm = (tl + tr) / 2;
    oof bl = que(v * 2, tl, tm, l, min(r, tm));
    oof br = que(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

    oof res;
    res.op = bl.op + br.op;
    res.cl = bl.cl + br.cl;
    res.tot = bl.tot + br.tot + min(bl.op - bl.tot / 2, br.cl - br.tot / 2) * 2;
    return res;
  };

  bui(1, 1, n);

  int m, l, r;
  cin >> m;
  while (m--) {
    cin >> l >> r;
    cout << que(1, 1, n, l, r).tot << '\n';
  }
  
  return 0;
}
