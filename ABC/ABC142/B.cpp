#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n,k;
  int ans =0;
  cin >> n >> k;
  for (int i=0; i<n; i++) {
    int h;
    cin >> h;
    if (h >= k) ans++;
  }

  cout << ans << endl;
}