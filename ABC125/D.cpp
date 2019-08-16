#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
  int n;
  int cnt=0;
  cin >> n;
  vector<long long> a(n);

  for (int i=0; i<n; i++) {
    cin >> a[i];
    if(a[i]<0) cnt++;
    a[i] = abs(a[i]);
  }

  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i=0; i<n; i++) ans+=a[i];
  if(cnt%2) ans-= 2*a[0];

  cout << ans << endl;
}