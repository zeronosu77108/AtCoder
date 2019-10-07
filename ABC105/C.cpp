#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  string ans;
  while (n != 0) {
    int r = abs(n%2);
    n = (n-r) / -2;
    ans += '0' + r;
  }
  if (ans == "") ans='0';
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}

/*
-9

*/