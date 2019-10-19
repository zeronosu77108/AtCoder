#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
  int n;
  int ans = 0;
  cin >> n;
  vector<int> d(n);
  for (int i=0; i<n; i++) cin >> d[i];

  int sum = accumulate(d.begin(), d.end(), 0);
  for (int i=0; i<n; i++) {
    ans += (sum-=d[i])*d[i];
  }

  cout << ans << endl;
}