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



*/

using pii = pair<int, int>;

int n, dist[mxn2];
vector<pii> adj[mxn2];

void solve() {
  cin >> n;
  FOR (i, 1, n) {
    int x, y, z;
    cin >> x >> y >> z;

    adj[i].eb(z, y);
    adj[i].eb(i + 1, x);

  }

  mems(dist, 0x2f);
  dist[1] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.em(dist[1], 1);

  while (!pq.empty()) {
    int x = pq.top().se, wei = pq.top().fi;
    pq.pop();
    if (wei > dist[x]) {
      continue;
    }

    each (i, adj[x]) {
      if (dist[i.fi] > dist[x] + i.se) {
        pq.em(dist[i.fi] = dist[x] + i.se, i.fi);
      }
    }

  }

  cout << dist[n] << '\n';

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
