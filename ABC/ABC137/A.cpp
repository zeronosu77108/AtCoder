#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int a,b;
  int ans = INT_MIN;
  cin >> a >> b;

  ans = max(ans,a+b);
  ans = max(ans,a-b);
  ans = max(ans,a*b);

  cout << ans << endl;
}