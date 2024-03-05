#include <stdio.h>
#include <algorithm>
using std::sort;

int main() {
  int n;
  long long m, k;
  scanf("%d%lld%lld", &n, &m, &k);
  long long a[n];
  for (long long &i : a) scanf("%lld", &i);

  sort(a, a + n);

  int ans = 0;
  m += k;
  for (long long &i : a) {
    if (m >= i) continue;
    
    ++ans;
    m = i;
    m += k;
  }
  printf("%d\n", ans);

}
