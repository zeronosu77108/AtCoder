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
  string c = s.substr(0, 1);
  int ans = 0;

  for (int i=1; i<=n; i++) {
    // cout << c << endl;

    if(c == s.substr(i,1)) {
      c = s.substr(i, 2);
      i++;
    } else {
      c = s.substr(i, 1);
    }
    ans++;
  }  

  cout << ans << endl;
}

/*
a|aa|c|ca|c|a|b|a|ab|a|b|c

*/