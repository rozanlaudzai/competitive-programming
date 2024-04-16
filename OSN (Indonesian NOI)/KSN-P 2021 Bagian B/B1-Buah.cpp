#include <bits/stdc++.h>
using namespace std;

int kpk(int a, int b) {
  int babu = a;
  while(a % b != 0) {
    a += babu;
  }
  return a;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  cout << kpk(a, b) / a + kpk(a, b) / b << endl;
}
