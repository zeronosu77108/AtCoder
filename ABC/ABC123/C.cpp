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
  cin >> n;
  long long mmin = LONG_MAX;
  for (long long i=0; i<5; i++) {
    long long m;
    cin >> m;
    mmin = min(mmin, m);
  }

  // cout << ceil(n/(long double)mmin)+4 << endl;
  printf("%ld\n", ((long)ceil(n/(long double)mmin)+4));
}

/*
5
3 2 4 3 5
5 4 3 3 2

0 0 0 0 0 6
6

並びでは変わらない．
ボトルネック 2 
*/