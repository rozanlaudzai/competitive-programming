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

#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define g3 get<3>
#define g4 get<4>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define cmin(a, b) a = min(a, b)
#define cmax(a, b) a = max(a, b)
#define mems(arr, a) memset(arr, a, sizeof arr)
#define db(x) cout << ">>> " << #x << " -> " << x << '\n'

#define FOR(i, a, n) for(int i = a; i < n; ++i)
#define UFOR(i, a, n) for(int i = a; i <= n; ++i)
#define RFOR(i, a, n) for(int i = a; i >= n; --i)
#define each(i, arr) for(auto &i : arr)

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<int, int, int, int, int> iiiii;

const int mxn1 = 1e5 + 10, mxn2 = 2e5 + 10, mod = 998244353;
const double PI = acos(-1);

/*

greedy:
  pokoknya sekalinya ada elemen yang sama atau lebih rendah maka dimasukkan set

*/

void solve() {
  int n;
  cin >> n;
  int a[n];
  each(i, a)
    cin >> i;
  
  set<int> babu;
  each(i, a) {
    set<int>::iterator it = babu.lower_bound(i);
    if(it == babu.end())
      babu.ins(i);
    else {
      babu.erase(it);
      babu.ins(i);
    }
  }
  
  cout << sz(babu) << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  // int t; cin >> t; while(t--)
  solve();

}
