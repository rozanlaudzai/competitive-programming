#include <stdio.h>
#include <algorithm>
using std::sort;

int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  long long tot_a = 0, tot_b = 0, b[m];
  for(int i = 0; i != n; ++i) {
    scanf("%lld", &b[0]);
    tot_a += b[0];
  }
  for(int i = 0; i != m; ++i) {
    scanf("%lld", &b[i]);
    tot_b += b[i];
  }
  sort(b, b + m);
  long long ans = 0;
  int id = m - 1;
  while(id >= 0 && tot_a * m <= tot_b * n) {
    long long pake = b[id];
    while(b[id] == pake && id >= 0) {
      tot_a += pake;
      ans += pake;
      tot_b -= pake;
      ++n;
      --m;
      --id;
    }
  }
  if(id == -1) {
    printf("-1\n");
    return 0;
  }
  if(tot_a * m > tot_b * n)
    printf("%lld\n", ans);
  else
    printf("-1\n");
}
