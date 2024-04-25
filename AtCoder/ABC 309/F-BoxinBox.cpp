#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

/*

every number need an index but we can not use that number as an index cuz segtree would make it rte
thus, compress them

*/

const int mxn = 2e5 + 5, mod = 1e9 + 7, inf = 2e18;

int n, t[1200005]; // 2e5 * 2 * 4
array<int, 3> a;
set<int> st;
map<int, int> id;
map<int, vector<pair<int, int>>> rem;

int que(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return inf;
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
    if (pos <= tm) {
      upd(v * 2, tl, tm, pos, val);
    } else {
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    }

    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) {

    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[0] >> a[1] >> a[2];
      sort(a.begin(), a.end());

      st.insert(a[1]);
      st.insert(a[2]);

      rem[a[0]].emplace_back(a[1], a[2]);
    }

    // compress
    int babu = 0;
    for (auto &i : st) {
      id[i] = ++babu;
    }

    memset(t, 0x2f, sizeof t);

    for (auto &i : rem) {

      // is there any less than
      for (auto &j : i.se) {
        if (que(1, 1, babu, 1, id[j.fi] - 1) < id[j.se]) {
          cout << "Yes\n";
          return 0;
        }
      }

      // store it to segtree
      for (auto &j : i.se) {
        if (que(1, 1, babu, id[j.fi], id[j.fi]) > id[j.se]) {
          upd(1, 1, babu, id[j.fi], id[j.se]);
        }
      }

    }

    cout << "No\n";
  }

}
