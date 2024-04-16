// greedy: pokoknya sekalinya ada elemen yang sama atau lebih rendah maka dimasukkan set

#include <stdio.h>
#include <set>
using std::multiset;

int n, a;
multiset<int> st;
multiset<int>::iterator it;

int main() {
  scanf("%d", &n);

  while (n--) {
    scanf("%d", &a);
    
    it = st.lower_bound(a);

    if (it == st.end()) st.insert(a);
    else {
      st.erase(it);
      st.insert(a);
    }
  }

  printf("%d\n", st.size());
}
