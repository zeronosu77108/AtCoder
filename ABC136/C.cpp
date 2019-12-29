#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n;
  bool ans = true;
  cin >> n;
  vector<int> h(n);

  for(int i=0; i<n; i++) {
    cin >> h[i];
  }

  for(int i=n-1; i>0; i--) {
    if(h[i-1] > h[i]) {
      if(h[i-1]-1 <= h[i]) h[i-1]--;
      else ans = false;
    }
  }

  cout << (ans? "Yes" : "No") << endl;
}