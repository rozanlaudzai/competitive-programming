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

typedef vector<int> vi;
typedef pair<int, int> pii;

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mod = 1e9 + 7, inf = 1000000000000000001;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double PI = acos(-1);

/*

k -> k * a
x -> impossible to loses more than x times in a row
a -> cur coins

product (k - 1) * bet harus bisa melebihi kerugian

3 3 6
6 - 1
6 - 1
6 - 2

k = 25
x = 69
a = 231

rugi = f
bet = a
a * k > f + a
a * (k - 1) > f

*/

void solve() {
  int k, x, a;
  cin >> k >> x >> a;

  int rugi = 1, need;
  while (--x && rugi < a) {
    need = rugi / (k - 1) + 1;

    rugi += need;
  }
  if (rugi >= a) {
    cout << "NO\n";
    return;
  }

  need = rugi / (k - 1) + 1;

  cout << (need > a - rugi ? "NO\n" : "YES\n");

}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  // int x = 1;
  int tc; cin >> tc; while (tc--)
  // {
  // cout << "Case #" << x++ << ": ";
  solve();
  // }

}
