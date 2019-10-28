#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int main() {
  long double a,b,x;
  long double ans;
  cin >> a >> b >> x;

  x /= a; // 奥行きを消す（平面で考える）

  // 半分より多いか少ないかで場合分けをする
  if (x <= a*b/2) { 
    ans = atan2(b, 2*x/b);
  } else {
    ans = atan2(2*(b-x/a), a);
  }

  cout << setprecision(14) << ans * 180.0 / M_PI << endl;
}