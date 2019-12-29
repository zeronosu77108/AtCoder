#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  long n;
  cin >> n;
  long ans = LONG_MAX;

  long stop = sqrt(n);
  for (int i=1; i<=stop; i++) {
    if (n%i==0) ans = min(ans, i+n/i);
  }
  
  cout << ans-2 << endl;
}