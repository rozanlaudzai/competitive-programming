#include <bits/stdc++.h>
using namespace std;

/*

k = banyak kandang
p = kapasitas banyak bebek
c = harga per kg
n = banyak bebek
b = berat bebek

*/

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int k;
  cin >> k;
  pair<long long, int> cp[k];
  for(int i = 0; i != k; ++i)
    cin >> cp[i].second;
  for(int i = 0; i != k; ++i)
    cin >> cp[i].first;
  sort(cp, cp + k);
  int n;
  cin >> n;
  long long b[n];
  for(long long &i : b)
    cin >> i;
  sort(b, b + n);

  long long ans = 0;
  int cekpo = n - 1;
  for(int i = 0; i != k; ++i) {
    while(cekpo >= 0 && cp[i].second > 0) {
      --cp[i].second;
      ans += b[cekpo--] * cp[i].first;
    }
  }

  cout << ans << '\n';

}
