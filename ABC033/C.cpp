#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;

  int i = 0;
  while (i<n) {
    bool f = true;
    while (i<n && s[i]!='+') {
      if (s[i] == '0') f = false;
      i++;
    }
    i++;
    if (f) ans++;
  }

  cout << ans << endl;
}