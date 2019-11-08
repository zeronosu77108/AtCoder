#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int ans;
  cin >> ans;
  for (int i=0; i<9; i++) {
    int a;
    cin >> a;
    ans -= a;
  }

  cout << ans << endl;
}