#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<int> st, en;
    for (auto &i : flowers) {
      st.push_back(i[0]);
      en.push_back(i[1]);
    }
    sort(st.begin(), st.end());
    sort(en.begin(), en.end());

    vector<int> ans;
    for (auto &i : people) {
      ans.push_back((upper_bound(st.begin(), st.end(), i) - st.begin()) - (lower_bound(en.begin(), en.end(), i) - en.begin()));
    }

    return ans;
  }
};
