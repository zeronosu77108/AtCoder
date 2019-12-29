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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);

  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++) cin >> b[i];
  for (int i=1; i<n; i++) cin >> c[i];

  int ans = 0;

  for (int i=0; i<n; i++) {
    ans += b[a[i]-1];
    if (i!=n-1 && a[i]+1 == a[i+1]) ans+=c[a[i]];
    // cout << ans << endl;
  }

  cout << ans << endl;
}