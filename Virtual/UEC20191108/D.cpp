#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n,k;
  map<string,bool> ans;
  cin >> n >> k;
  vector<string> ks(n);
  for (int i=0; i<n; i++) cin>>ks[i];
  sort(ks.begin(), ks.end());

  do {
    string s;
    for (int i=0; i<k; i++) s+=ks[i];
    ans[s] = true;
  } while (next_permutation(ks.begin(),ks.end()));

  cout << ans.size() << endl;
}