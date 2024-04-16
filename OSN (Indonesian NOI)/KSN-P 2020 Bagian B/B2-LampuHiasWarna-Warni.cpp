#include <stdio.h>
#include <algorithm>

int main() {

  int n;
  scanf("%d", &n);
  char c;
  int a[26] = {0};
  scanf("%c", &c);
  while(n--) {
    scanf("%c", &c);
    ++a[c - 65];
  }
  std::sort(a, a + 26);

  if(a[23] == 0) {
    printf("-1\n");
    return 0;
  }

  if(a[25] > a[23])
    ++n;
  if(a[24] > a[23])
    ++n;

  printf("%d\n", a[23] * 3 + n + 1);

}
