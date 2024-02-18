#include <bits/stdc++.h>
using namespace std;

#define int long long
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
#define db(x) cout << ">>> " << #x << " -> " << (x) << '\n'

#define FOR(i, a, n) for (int i = a; i < (n); ++i)
#define UFOR(i, a, n) for (int i = a; i <= (n); ++i)
#define RFOR(i, a, n) for (int i = a; i >= (n); --i)
#define each(i, arr) for (auto &i : arr)

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mod = 1e9 + 7, inf = 1000000000000000001;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double PI = acos(-1);

/*

ketika upd, yg berdampak hanya l - 1 dan r + 1

*/

int n, q, x, l, r, a[500005], t[2000005];
string s;

void bui(int v, int tl, int tr) {
  
  if(tl == tr) {
    t[v] = a[tl];
  }
  else {
    int tm = (tl + tr) / 2;
    bui(v * 2, tl, tm);
    bui(v * 2 + 1, tm + 1, tr);
    
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

int que(int v, int tl, int tr, int l, int r) {

  if(l > r) {
    return 0;
  }
  if(l == tl && r == tr) {
    return t[v];
  }

  int tm = (tl + tr) / 2;

  return que(v * 2, tl, tm, l, min(r, tm)) + que(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void upd(int v, int tl, int tr, int pos, int val) {
  if(tl == tr) {
    t[v] = val;
  }
  else {

    int tm = (tl + tr) / 2;

    if(tm >= pos) {
      upd(v * 2, tl, tm, pos, val);
    }
    else {
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    }

    t[v] = t[v * 2] + t[v * 2 + 1];

  }
}

void solve() {
  cin >> n >> q >> s;
  each (i, s) {
    i -= '0';
  }
  s = " " + s;
  FOR (i, 1, n) {
    if (s[i] != s[i + 1]) {
      a[i] = 1;
    }
  }

  if (n != 1) {
    --n;
    bui(1, 1, n);
  }

  while (q--) {
    cin >> x >> l >> r;

    if (n == 1 && x == 2) {
      cout << "Yes\n";
      continue;
    }

    if (x == 1) {
      if (l != 1) {
        if (que(1, 1, n, l - 1, l - 1)) {
          upd(1, 1, n, l - 1, 0);
        } else {
          upd(1, 1, n, l - 1, 1);
        }
      }

      if (r != n + 1) {
        if (que(1, 1, n, r, r)) {
          upd(1, 1, n, r, 0);
        } else {
          upd(1, 1, n, r, 1);
        }
      }

    } else {
      cout << (que(1, 1, n, l, r - 1) == r - l ? "Yes\n" : "No\n");
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
