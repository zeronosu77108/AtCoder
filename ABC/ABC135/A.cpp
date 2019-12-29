#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

long long main() {
  long long a,b;
  cin >> a >> b;
  if ( (a+b) %2==0) {
    cout << (a+b)/2 << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}