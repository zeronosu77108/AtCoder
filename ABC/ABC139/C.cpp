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

  int h1,h2;
  cin >> h1;
  int cnt = 0;
  int ans = 0;
  for (int i=1; i<n; i++) {
    cin >> h2;
    if (h1>=h2) {
      cnt++;
      if(cnt>ans) ans = cnt;
    } else cnt=0;
    h1 = h2;
  }
  cout << ans << endl;
}