#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n,m;
  int current = 1;
  int ans = 0;
  cin >> n >> m;
  vector<int> box(n+1);
  for (int i=1; i<=n; i++) cin >> box[i];

  for (int i=1; i<=m; i++) {
    int d;
    cin >> d;
    if (current+d >= n) {
      ans = i;
      break;
    }
    current += d + box[current+d];
    if (current >= n) {
      ans = i; break;
    }
  }

  cout << ans << endl;
}