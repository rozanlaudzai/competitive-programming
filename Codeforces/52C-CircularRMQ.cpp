#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define ins insert
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define em emplace
#define eb emplace_back
#define ef emplace_front
#define lb lower_bound
#define ub upper_bound
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define g3 get<3>
#define g4 get<4>
#define bpc __builtin_popcountll

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define cmin(a, b) a = min(a, b)
#define cmax(a, b) a = max(a, b)
#define mems(arr, a) memset(arr, a, sizeof arr)
#define db(x) cerr << ">>> " << #x << " -> " << (x) << '\n'

#define FOR(i, a, n) for (int i = a; i < (n); ++i)
#define UFOR(i, a, n) for (int i = a; i <= (n); ++i)
#define RFOR(i, a, n) for (int i = a; i >= (n); --i)
#define each(i, arr) for (auto &i : arr)

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mxn3 = 3e5 + 10, mod = 1e9 + 7, inf = 1000000000000000001;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const ld PI = acos(-1);

/*



*/

int n, m, a[mxn2], t[800005], lazy[800005];

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

void push(int v) {
  t[v * 2] += lazy[v];
  lazy[v * 2] += lazy[v];
  t[v * 2 + 1] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int add) {
  if (l > r) {
    return;
  }
  if (tl == l && tr == r) {
    t[v] += add;
    lazy[v] += add;
  } else {

    push(v);

    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), add);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

int que(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return inf;
  }
  if (tl == l && tr == r) {
    return t[v];
  }

  push(v);

  int tm = (tl + tr) / 2;
  return min(
    que(v * 2, tl, tm, l, min(r, tm)),
    que(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
  );
}

void solve() {
  cin >> n;
  UFOR (i, 1, n) {
    cin >> a[i];
  }

  bui(1, 1, n);

  string babu;

  cin >> m;
  getline(cin, babu);
  while (m--) {
    getline(cin, babu);

    int v[3] = {}, id = 0;
    bool neg = false;

    each (i, babu) {
      if (i == '-') {
        neg = true;
      } else if (i == ' ') {
        ++id;
      } else {
        v[id] *= 10LL;
        v[id] += (int)(i - '0');
      }
    }
    if (neg) {
      v[id] = -v[id];
    }

    ++v[0];
    ++v[1];

    if (id == 1) {
      if (v[0] > v[1]) {
        cout << min(que(1, 1, n, v[0], n), que(1, 1, n, 1, v[1])) << '\n';
      } else {
        cout << que(1, 1, n, v[0], v[1]) << '\n';
      }
    } else {
      if (v[0] > v[1]) {
        upd(1, 1, n, v[0], n, v[2]);
        upd(1, 1, n, 1, v[1], v[2]);
      } else {
        upd(1, 1, n, v[0], v[1], v[2]);
      }
    }

  }
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  // int x = 1;
  // int tc; cin >> tc; while (tc--)
  // {
  // cout << "Case #" << x++ << ": ";
  solve();
  // }

}
