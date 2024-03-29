/*

Final Olimpiade Sains Al Azhar 2024
C. Wawancara

*/

#include <stdio.h>
#include <queue>
#include <algorithm>
using std::sort;
using std::queue;
using std::max;

int main() {

  int n, k, d;
  scanf("%d%d%d", &n, &k, &d);
  int a[n];

  for (int &i : a) {
    scanf("%d", &i);
  }

  sort(a, a + n);

  queue<int> q;

  for (int &i : a) {
    if (q.size() == k) {

      q.push(max(q.front(), i) + d);
      q.pop();

    } else {

      q.push(i + d);

    }
  }

  while (q.size() > 1) {
    q.pop();
  }

  printf("%d", q.front());
}
