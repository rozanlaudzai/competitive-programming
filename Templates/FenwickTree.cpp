#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5 + 5;
int n, a[mxn];

void upd(int idx, int val) {
  while(idx <= n) {
    a[idx] += val;
    idx += idx & -idx;
  }
}

int sum(int idx) { // from index 1 until idx
  int res = 0;
  while(idx > 0) {
    res += a[idx];
    idx -= idx & -idx;
  }
  return res;
}
