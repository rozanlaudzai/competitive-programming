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

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define cmin(a, b) a = min(a, b)
#define cmax(a, b) a = max(a, b)
#define mems(arr, a) memset(arr, a, sizeof arr)
#define db(a) cerr << ">>> " << #a << " -> " << (a) << '\n'

#define FOR(i, a, n) for (int i = a; i < (n); ++i)
#define UFOR(i, a, n) for (int i = a; i <= (n); ++i)
#define RFOR(i, a, n) for (int i = a; i >= (n); --i)
#define each(i, arr) for (auto &i : arr)

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mxn3 = 3e5 + 10, mod = 1e9 + 7, inf = 1000000000000000001;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const ld PI = acos(-1);

/*

UB - LB start from l to r
UB - LB start from r to l

*/

int n, k, oof, a[mxn2], tor[mxn2], tol[mxn2], ttor[800005], ttol[800005];

void bui1(int v, int tl, int tr) {
  if (tl == tr) {
    ttor[v] = tor[tl];
  } else {
    int tm = (tl + tr) / 2;
    bui1(v * 2, tl, tm);
    bui1(v * 2 + 1, tm + 1, tr);
    
    ttor[v] = max(ttor[v * 2], ttor[v * 2 + 1]);
  }
}

int que1(int v, int tl, int tr, int l, int r) {

  if (l > r) {
    return 0;
  }
  if (l == tl && r == tr) {
    return ttor[v];
  }

  int tm = (tl + tr) / 2;
  return max(
    que1(v * 2, tl, tm, l, min(r, tm)),
    que1(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
  );

}

void bui2(int v, int tl, int tr) {
  if (tl == tr) {
    ttol[v] = tol[tl];
  } else {
    int tm = (tl + tr) / 2;
    bui2(v * 2, tl, tm);
    bui2(v * 2 + 1, tm + 1, tr);
    
    ttol[v] = max(ttol[v * 2], ttol[v * 2 + 1]);
  }
}

int que2(int v, int tl, int tr, int l, int r) {

  if (l > r) {
    return 0;
  }
  if (l == tl && r == tr) {
    return ttol[v];
  }

  int tm = (tl + tr) / 2;
  return max(
    que2(v * 2, tl, tm, l, min(r, tm)),
    que2(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
  );

}

void solve() {
  cin >> n >> k;
  UFOR (i, 1, n) {
    cin >> a[i];
  }
  UFOR (i, 1, n) {
    cin >> oof;
  }

  sort(a + 1, a + n + 1);

  UFOR (i, 1, n) {
    tor[i] = ub(a + 1, a + n + 1, a[i] + k) - (a + i);
    tol[i] = (a + i) - (lb(a + 1, a + n + 1, a[i] - k) - 1);
  }

  bui1(1, 1, n);
  bui2(1, 1, n);

  int ans = 0;
  UFOR (i, 1, n) {

    if (1 < i) {
      cmax(ans, tor[i] + que2(1, 1, n, 1, i - 1));
    }
    if (i < n) {
      cmax(ans, tol[i] + que1(1, 1, n, i + 1, n));
    }

    if (i + tor[i] <= n) {
      cmax(ans, tor[i] + que1(1, 1, n, i + tor[i], n));
    } else {
      cmax(ans, tor[i]);
    }

    if (i - tol[i] >= 1) {
      cmax(ans, tol[i] + que2(1, 1, n, 1, i - tol[i]));
    } else {
      cmax(ans, tol[i]);
    }

  }

  cout << ans << '\n';

}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  // int a = 1;
  int tc; cin >> tc; while (tc--)
  // {
  // cout << "Case #" << a++ << ": ";
  solve();
  // }

}
