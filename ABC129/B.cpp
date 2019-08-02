#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n;
  int ans = INT_MAX;
  cin >> n;

  vector<int> w(n);
  vector<int> left(n);
  vector<int> right(n);

  for(int i=0; i<n; i++) {
    cin >> w[i];
    left[i] = (i==0? w[i] : left[i-1]+w[i]);
  }

  for(int i=0; i<n; i++) {
    right[n-i-1] = (i==0? w[n-i-1] : right[n-i]+w[n-i-1]);
  }

  for(int i=0; i<n-1; i++) {
    ans = min(ans, abs(left[i]-right[i+1]));
  }

  cout << ans << endl;
}