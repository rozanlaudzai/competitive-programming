#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  string s = b + "#" + a;
  int n = s.size(), pi[n] = {};

  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];

    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }

    if (s[i] == s[j]) {
      ++j;
    }

    pi[i] = j;
  }

  int ans = 0;
  for (int i = b.size() + 1; i < n; ++i) {
    if (pi[i] == b.size()) {
      ++ans;
    }
  }
  cout << ans << '\n';

}
