#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if(b > 0)
    return gcd(b, a % b);
  return a;
}

long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  long long p, q, r, n;
  cin >> p >> q >> r >> n;
  p = lcm(p, q);
  p = lcm(p, r);
  while(n--) {
    cin >> q;
    if(q % p == 0) cout << "YA\n";
    else cout << "TIDAK\n";
  }

}
