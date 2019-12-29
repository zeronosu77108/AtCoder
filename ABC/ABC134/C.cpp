#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

typedef pair<int,int> P;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);

  for(int i=0; i<n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b.begin(),b.end(), greater<int>());

  for(int i=0; i<n; i++) {
    if (a[i] == b[0]) {
      cout << b[1] << endl;
    } else {
      cout << b[0] << endl;
    }
  }

}