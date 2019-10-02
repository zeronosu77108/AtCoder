#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector<long> enumDiviser(long n) {
  vector<long> res(1,1);

  for (long i=2; i*i<=n; i++) {
    if (n%i==0) {
      res.push_back(i);
      if (i*i != n) res.push_back(n/i);
    }
  }

  res.push_back(n);
  return res;
}

int main() {
  long n,m;
  long ans = -1;
  cin >> n >> m;
  vector<long> divisers = enumDiviser(m);
  sort(divisers.rbegin(), divisers.rend());

  for (auto diviser : divisers) {
    if (n <= m/diviser) ans = diviser;
    if (ans > 0) break;
  }

  cout << ans << endl;
}