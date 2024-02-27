#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  int mini = 100, x = 1, p[n];
  for(int &i : p)
    cin >> i;
  sort(p, p + n);
  for(int i = 1; i != n; ++i)
    mini = min(mini, p[i] - p[i - 1]);
  for(int i = 2; i <= mini; ++i)
    x *= i;
  cout << x << '\n';

}
