#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long double> a(n);

  for (int i=0; i<n; i++) cin >> a[i];

  long double sum = 0;

  for (int i=0; i<n; i++) sum += 1/a[i];

  printf("%.14Lf\n",(1/sum));
}