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
  int ans = 0;
  int n = s.size()/2;

  while (n > 1) {
    n--;
    if (s.substr(0,n) == s.substr(n,n)) 
      ans = max(ans,2*n);
  }

  cout << ans << endl;
}