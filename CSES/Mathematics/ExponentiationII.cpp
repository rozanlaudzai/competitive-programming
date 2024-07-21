#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

/*

a^(b^c) % mod
obviously binpow

b^c = (mod - 1) * divi + rem

fermat's little theorem
a^p % p = a
a^(p - 1) % p = 1
a^(p - 2) % p = 1 / a

a^((mod - 1) * divi) * a^rem
= 1 * a^rem

how do we get rem?
eliminate (mod - 1) * divi
b^c % (mod - 1) = ((mod - 1) * divi + rem) % (mod - 1) = rem

*/

const ll mod = 1e9 + 7;

ll pw(ll a, ll b, ll m) {
  ll res = 1;
  a %= m;
  while (b > 0) {
    if (b % 2 == 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b /= 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << pw(a, pw(b, c, mod - 1), mod) << '\n';
  }

  return 0;
}
