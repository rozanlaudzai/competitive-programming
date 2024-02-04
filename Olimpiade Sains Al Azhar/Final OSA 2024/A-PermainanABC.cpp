/*

Final Olimpiade Al Azhar 2024
A. Permainan ABC

*/

#include <stdio.h>

int a, id = 1, f[100] = {1, 1};

int main() {

  scanf("%d", &a);
  do {
    ++id;
    f[id] = f[id - 1] + f[id - 2];
  } while (a % f[id] && f[id] < a);

  printf("%d\n", (a % f[id] ? -1 : a / f[id] * f[id - 1]));

}
