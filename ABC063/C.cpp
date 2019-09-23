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
  int n;
  cin >> n;
  int ans = 0;
  int smin = INT_MAX;

  for (int i=0; i<n; i++) {
    int s;
    cin >> s;
    ans += s;
    if (s%10!=0) smin = min(smin, s);
  }

  if (ans%10==0) ans -= (smin>100? ans : smin);
  cout << ans << endl;
}