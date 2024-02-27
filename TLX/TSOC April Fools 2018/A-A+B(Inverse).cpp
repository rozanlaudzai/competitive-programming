#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int a;
  cin >> a;
  if(a == 1)
    cout << "0 1\n";
  else if(a % 2 == 0)
    cout << a / 2 << ' ' << a / 2 << '\n';
  else if(a % 3 == 0)
    cout << a / 3 << ' ' << a / 3 * 2 << '\n';
  else if(a % 5 == 0)
    cout << a / 5 << ' ' << a / 5 * 4 << '\n';
  else if(a % 7 == 0)
    cout << a / 7 << ' ' << a / 7 * 6 << '\n';
  else
    cout << "1 " << a - 1 << '\n';

}
