#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  long long n;
  long long ans=0;
  cin >> n;
  vector<long long> a(n+1);
  for(long long i=0; i<=n; i++) cin >> a[i];

  for(long long i=0; i<n; i++) {
    long long b;
    cin >> b;

    if(a[i] <= b) {
      ans += a[i];
      b -= a[i];
    } else {
      ans += b;
      b=0;
    }

    if(a[i+1] <= b) {
      ans += a[i+1];
      a[i+1]=0;
    } else {
      ans += b;
      a[i+1] -= b;
    }

  }
  cout << ans << endl;
}