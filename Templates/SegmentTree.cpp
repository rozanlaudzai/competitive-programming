// segtree rmq

#include <bits/stdc++.h>
using namespace std;

int n, a[200005], t[800005];

void bui(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    bui(v * 2, tl, tm);
    bui(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

int que(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return INT_MAX;
  }
  if (tl == l && tr == r) {
    return t[v];
  }

  int tm = (tl + tr) / 2;
  return min(
    que(v * 2, tl, tm, l, min(r, tm)),
    que(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
  );
}

void upd(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = val;
  } else {
    int tm = (tl + tr) / 2;
    if (tm >= pos) {
      upd(v * 2, tl, tm, pos, val);
    } else {
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    }
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

int main() {

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  bui(1, 1, n);

}
