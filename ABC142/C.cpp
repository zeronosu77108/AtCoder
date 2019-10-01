#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin>>a[i];
  vector<int> ans(n);
  iota(ans.begin(), ans.end(), 0);

  sort(ans.begin(), ans.end(), 
    [&](int x, int y) { return a[x] < a[y]; });
    //[](int x,int y){return (a[x]>a[y]);}

  for (int i=0; i<n; i++) cout << ans[i]+1 << endl;
}