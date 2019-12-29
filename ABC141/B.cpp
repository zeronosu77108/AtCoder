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
  string s;
  cin >> s;
  int n = s.size();
  bool ans = true;

  for (int i=0; i<n; i++) {
    if (i%2 && s[i]=='R') ans = false;
    if (!(i%2) && s[i]=='L') ans = false;
  }

  cout << (ans? "Yes" : "No") << endl;
}