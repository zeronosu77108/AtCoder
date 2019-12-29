#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int main() {
  string s,t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  bool ans = false;

  for (int i=n-1; i>=0; i--) {
    bool f = true;  
    for (int j=0; j<min(n,m); j++) {
      if (s[i-j] != t[m-j-1] && s[i-j] != '?') {
        f = false;
        break;
      }
    }

    if (f) {
      for (int j=0; j<min(n,m); j++) {
        s[i-j] = t[m-j-1];
      }
      ans = true;
      break;
    }
  }
  ans = ans && n>=m;
  if (ans) {
    for (auto c : s)
      cout << (c=='?'? 'a' : c);
    cout << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
}