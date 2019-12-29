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
  cin >> n;
  vector<int> l(n);
  for (int i=0; i<n; i++) cin>>l[i];
  sort(l.begin(),l.end());
  // for (auto i:l)cout<<i<<" ";cout<<endl;

  int ans = 0;
  for (int i=n-1; i>=0; i--) {
    for (int j=i-1; j>=0; j--) {
      auto it = upper_bound(l.begin(),l.end(), l[i]-l[j]);
      ans += max(0, (int)((l.begin()+j) - it));
    }
  }
  cout << ans << endl;
}
/*
1 2 3 4
218 233 389 645 704 728 786 
*/