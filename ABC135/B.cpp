#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

long long main() {
  long long n;
  cin >> n;
  long long count=0;

  for(long long i=1; i<=n; i++) {
    long long t;
    cin >> t;
    if(t != i) count++;
  }

  cout << (count>2 ? "NO" : "YES") << endl;
}