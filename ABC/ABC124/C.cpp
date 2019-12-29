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
  int ans=0;
  bool f = (s[0] == '0');

  for (int i=1; i<n; i++) {
    if (f) {
      if (s[i] == '0') ans++;
    } else {
      if (s[i] == '1') ans++;
    }
    f = !f;
  }

  cout << ans << endl;
}