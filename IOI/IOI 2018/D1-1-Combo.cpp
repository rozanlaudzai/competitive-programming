#include "combo.h"
#include <bits/stdc++.h>
using namespace std;

string guess_sequence(int n) {

  // guess 1st char of s
  // remaining questions: n + 2 - 2 = n
  string s;
  int val = press("AB");
  
  if (val == 2) {
    s = "A";
  } else if (val == 1) {
    
    if (press("A") == 1) {
      s = "A";
    } else {
      s = "B";
    }
    
  } else {
    
    if (press("X") == 1) {
      s = "X";
    } else {
      s = "Y";
    }
    
  }
  
  if (n == 1) {
    return s;
  }

  // remaining length: (n - 1)
  vector<string> ch;
  if (s[0] != 'A') {
    ch.push_back("A");
  }
  if (s[0] != 'B') {
    ch.push_back("B");
  }
  if (s[0] != 'X') {
    ch.push_back("X");
  }
  if (s[0] != 'Y') {
    ch.push_back("Y");
  }

  for (int i = 2; i <= n - 1; ++i) {

    val = press(s + ch[0] + s + ch[1] + ch[0] + s + ch[1] + ch[1] + s + ch[1] + ch[2]);

    if (val == i - 1) {
      s += ch[2];
    } else if (val == i) {
      s += ch[0];
    } else { // val == i + 1
      s += ch[1];
    }
  }

  if (press(s + ch[0]) == n) {
    s += ch[0];
  } else if (press(s + ch[1]) == n) {
    s += ch[1];
  } else {
    s += ch[2];
  }
  
  return s;
}
