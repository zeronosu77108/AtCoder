#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
  if (a==1 || b==1) return 1;
  int r = a%b;
  if (r == 0) return b;
  return gcd(b, r);
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> l(n);
  vector<int> r(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  if (n<=2) {
    cout << max(a[0],a[1]) << endl;
    return 0;
  }

  l[0] = a[0];
  r[n-1] = a[n-1];

  for (int i=1; i<n; i++) {
    l[i] = gcd(l[i-1], a[i]);
    r[n-i-1] = gcd(r[n-i],  a[n-i-1]);
  }

  // for (int i=0; i<n; i++) cout << l[i] << " ";
  // cout << endl;

  // for (int i=0; i<n; i++) cout << r[i] << " ";
  // cout << endl;

  int ans = max(l[n-2],r[1]);
  for (int i=1; i<n-1; i++) {
    ans = max(ans, gcd(l[i-1], r[i+1]));
  }

  cout << ans << endl;
}