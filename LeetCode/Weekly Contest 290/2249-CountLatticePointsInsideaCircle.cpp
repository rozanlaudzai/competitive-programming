#include <bits/stdc++.h>
using namespace std;
// mantap
class Solution {
public:
  int countLatticePoints(vector<vector<int>>& circles) {
    set<pair<int, int>> st;

    for (auto &i : circles) {
      for (int j = -i[2]; j <= i[2]; ++j) {
        for (int k = -i[2]; k <= i[2]; ++k) {
          if (j * j + k * k <= i[2] * i[2]) {
            st.insert({i[0] + j, i[1] + k});
          }
        }
      }
    }
    return st.size();
  }
};
