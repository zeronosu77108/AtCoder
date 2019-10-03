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
  long n;
  long ans = 0;
  cin >> n;
  vector<long> b;

  for (long i=1; i<=n; i++) {
    long a; cin>>a;
    b.push_back(a-i);
  }

  sort(b.begin(), b.end());
  long B = (n%2? b[n/2] : (b[n/2-1]+b[n/2])/2);
  ans = accumulate(b.begin(),b.end(),0L,
    [&](long acc, long i) {return acc + abs(i-B);});
  cout << ans << endl;

}