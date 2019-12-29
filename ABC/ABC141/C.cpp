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
  long n,k,q;
  cin >> n >> k >> q;
  vector<long> a(n+1,0);

  for (int i=0; i<q; i++) {
    int ai;
    cin >> ai;
    a[ai]++;
  }

  for (int i=1; i<=n; i++) {
    bool ans = (q-a[i] < k);
    cout << (ans? "Yes" : "No") << endl;
  }
}