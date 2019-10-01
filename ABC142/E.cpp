#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <bitset>


using namespace std;

int main() {
  long n,m;
  cin >> n >> m;
  vector<long> costs;
  vector<long> open;
  vector<long> dp(1<<n, -1);

  for (int i=0; i<m; i++) {
    long a,b;
    cin >> a >> b;

    long cnt = 0;
    for (long j=0; j<b; j++) {
      long c;
      cin >> c;
      cnt += 1<<(c-1);
    }
    // cout << cnt << endl;
    costs.push_back(a);
    open.push_back(cnt);
  }

  dp[0] = 0; 
  for (long i=0; i<m; i++) {
    dp[open[i]] = costs[i];
  }

  for (long i=0; i<(1<<n); i++) {
    if(dp[i]<0) continue;

    for (long j=0; j<m; j++) {
      long index = (i | open[j]);
      if (dp[index]<0) dp[index] = dp[i] + costs[j];
      else 
        dp[index] = min(dp[index], dp[i] + costs[j]);
    }
  }

  cout << dp[(1<<n)-1] << endl;
}