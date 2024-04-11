#include <bits/stdc++.h>
using namespace std;
// mantap
class Solution {
public:
vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {

  vector<vector<int>> xs(105);
  for (auto &i : rectangles) {
    xs[i[1]].push_back(i[0]);
  }
  for (int i = 1; i <= 100; ++i) {
    if (!xs[i].empty()) {
      sort(xs[i].begin(), xs[i].end());
    }
  }

  vector<int> ans;

  for (auto &v : points) {
    int cnt = 0;
    for (int i = v[1]; i <= 100; ++i) {
      if (!xs[i].empty()) {
        int n = xs[i].size(), l = 0, r = xs[i].size() - 1, jadi = n;
        while (l <= r) {
          int m = (l + r) / 2;
          if (xs[i][m] < v[0]) {
            l = m + 1;
          } else {
            r = m - 1;
            jadi = m;
          }
        }
        cnt += n - jadi;
      }
    }
    ans.push_back(cnt);
  }

  return ans;
}
};
