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
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> dp(n,0);


  for (int i=1; i<n; i++) {
    if (i!=1) dp[i] = dp[i-1];
    if (s[i-1]=='A' && s[i]=='C') dp[i]++;
  }

  for (auto d : dp) cerr << d << " ";
    cerr << endl;

  for (int i=0; i<q; i++) {
    int l,r;
    cin >> l >> r;
    cout << dp[r-1] - dp[l-1] << endl;
  }
}