/*

Final Olimpiade Sains Al Azhar 2024
B. Menanam Padi

*/

#include <stdio.h>

const int mn = 1000001;
int n, m, q, a, b, ans, lx, ly;
bool x[mn], y[mn];

int main() {

  scanf("%d%d%d", &n, &m, &q);

  while (q--) {
    ans = 0;

    scanf("%d%d", &a, &b);

    if (!x[a]) {
      x[a] = true;
      ++lx;
      ans += m - ly;
    }

    if (!y[b]) {
      y[b] = true;
      ++ly;
      ans += n - lx;
    }

    printf("%d\n", ans);
  }

}
