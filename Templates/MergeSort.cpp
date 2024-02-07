#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &left, vector<int> &right, vector<int> &arr) {

  int i = 0, l = 0, r = 0;

  while (l < left.size() && r < right.size()) {
    if (left[l] > right[r]) {
      arr[i++] = right[r++];
    } else {
      arr[i++] = left[l++];
    }
  }

  while (l < left.size()) {
    arr[i++] = left[l++];
  }
  
  while (r < right.size()) {
    arr[i++] = right[r++];
  }

}

void mergeSort(vector<int> &arr) {
  if (arr.size() <= 1) {
    return;
  }
  vector<int> left, right;

  int m = arr.size() / 2;

  for (int i = 0; i < m; ++i) {
    left.push_back(arr[i]);
  }
  
  for (int i = m; i < arr.size(); ++i) {
    right.push_back(arr[i]);
  }

  mergeSort(left);
  mergeSort(right);
  merge(left, right, arr);

}
