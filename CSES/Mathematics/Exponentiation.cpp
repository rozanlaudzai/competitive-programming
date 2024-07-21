#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

// binary exponentiation

const ll mod = 1e9 + 7;

ll pw(ll a, ll b) {
  ll res = 1;
  a %= mod;
  while (b > 0) {
    if (b % 2 == 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
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
    ll a, b;
    cin >> a >> b;
    cout << pw(a, b) << '\n';
  }

  return 0;
}
