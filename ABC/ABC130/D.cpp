#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  long n,k;
  long ans = 0;
  cin >> n >> k;
  vector<long> a(n);
  for (int i=0; i<n; i++) cin>>a[i];

  long sum,r;
  sum = r = 0;
  for (long l=0; l<n; l++) {
    while(r<n && sum<k) {
      sum += a[r++];
    }
    if (sum<k) break;

    ans += n - (r-1);
    sum -= a[l];
  }

  cout << ans << endl;
}