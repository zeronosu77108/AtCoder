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
  int n,m;
  m=0;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n,-1);

  for(int i=0; i<n; ++i) cin >> a[i];

  for(int i=n; i>0; --i) {
    bool f = a[i-1];
    int l = n/i;
    for(int j=l; j>0; --j) {
      if(b[i*j-1] == -1) {
        b[i*j-1] = f;
        if(f) m++;
        break;
      } else {
        if(b[i*j-1] == 1)
          f = !f;
      }
    }
  }

  cout << m << endl;
  for(int i=0; i<n; i++) {
    if(b[i] >= 1)
      cout << i+1 << endl;
  }
}