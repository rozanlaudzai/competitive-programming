#include <bits/stdc++.h>
using namespace std;

// 1-based indexing

const int maxn = 2e5 + 5;
int n, a[maxn];

void upd(int idx, int val) {
  while (idx < maxn) {
    a[idx] += val;
    idx += idx & -idx;
  }
}

int sum(int idx) {
  int res = 0;
  while (idx > 0) {
    res += a[idx];
    idx -= idx & -idx;
  }
  return res;
}
