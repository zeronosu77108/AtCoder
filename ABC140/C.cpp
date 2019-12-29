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
  cin>>n;
  int ans = 0;

  int b1,b2;
  cin >> b1;
  ans += b1;
  for (int i=1; i<n-1; i++) {
    cin >> b2;
    ans += min(b1,b2);
    b1 = b2;
  }
  ans += (n==2? b1 : b2);

  cout << ans << endl;
}