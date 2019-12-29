#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int ans = 0;
  int bmax = -1;
  for (int i=0; i<3; i++) {
    int a; cin>>a;
    ans += a;
    bmax = max(bmax,a);
  }

  cout << ans - bmax << endl;
}