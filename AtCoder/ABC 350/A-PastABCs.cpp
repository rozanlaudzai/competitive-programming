#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int a;
  stringstream ss;
  ss << s.substr(3, 3);
  ss >> a;

  if (a > 0 && a < 350 && a != 316) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  // int x = 1;
  // int tc; cin >> tc; while (tc--)
  // {
  // cout << "Case #" << x++ << ": ";
  solve();
  // }

}
