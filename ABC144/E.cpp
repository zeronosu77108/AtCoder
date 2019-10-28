#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int main() {
  long long n,k;
  cin >> n >> k;
  vector<long long> a(n);
  vector<long long> f(n);

  for (int i=0; i<n; i++) cin>>a[i];
  for (int i=0; i<n; i++) cin>>f[i];

  sort(a.begin(),a.end());
  sort(f.rbegin(),f.rend());

  long long l = -1;
  long long r = 1e12;
  while(l+1 < r) {
    long long g = (l+r)/2;
    bool flag = true;

    long long count = 0;
    for (long long i=0; i<n; i++) {
      count += max(0LL,(a[i] - g/f[i]));
      if (count > k) {
        flag=false;
        break;
      }
    }
    (flag? r : l) = g;
  }

  cout << r << endl;
}