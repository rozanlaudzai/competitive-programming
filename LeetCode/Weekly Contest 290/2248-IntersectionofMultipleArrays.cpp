#include <bits/stdc++.h>
using namespace std;
// mantap
class Solution {
public:
  vector<int> intersection(vector<vector<int>>& nums) {
    int cnt[1005] = {};
    for (auto &i : nums) {
      bool vis[1005] = {};
      for (auto &j : i) {
        if (!vis[j]) {
          ++cnt[j];
        }
        vis[j] = true;
      }
    }
    vector<int> ans;
    for (int i = 1; i <= 1000; ++i) {
      if (cnt[i] == nums.size()) {
        ans.push_back(i);
      }
    }
    sort(ans.begin(), ans.end());

    return ans;
  }
};
