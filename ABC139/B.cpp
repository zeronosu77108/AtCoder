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
  int a,b;
  cin >> a >> b;

  int ans = 0;
  int tap = 1;

  a--;
  while(tap < b) {
    tap += a;
    ans++;
  }
  cout << ans << endl;
}