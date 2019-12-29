#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int mod = 1000000007;

int main() {
  int n,m;
  cin >> n >> m;
  vector<long> dp(n+1,-1);

  for (int i=0; i<m; i++) {
    int a;
    cin >> a;
    dp[a] = 0;
  }

  dp[0] = 1;

  for (int i=1; i<=n; i++) {
    if(dp[i] == -1) {
      dp[i] = dp[i-1];
      if(i>1) dp[i]+=dp[i-2];
      dp[i] %= mod;
    }
  }

  cout << dp[n] << endl;
}