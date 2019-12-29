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
  cin >> a >> b;
  int ans = 0;
  if (a>b) swap(a,b);
  ans += b--;
  if (a>b) swap(a,b);
  ans += b;

  cout << ans << endl;
}