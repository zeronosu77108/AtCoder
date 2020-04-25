#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>


using namespace std;

const int mod = 1000000007;


int main() {
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(),s.end());

  vector<vector<int>> dp(n+1, vector<int>(13,0));
  int digit=1;
  dp[0][0] = 1;
  for(int i=0; i<n; i++) {

    // 未確定のとき
    if(s[i] == '?') {
      for(int d=0; d<10; d++) {
        for(int j=0; j<13; j++) {
          dp[i+1][(d*digit + j)%13] += dp[i][j];
          dp[i+1][(d*digit + j)%13] %= mod;
        }
      }
    } 
    // 確定しているとき
    else {
        int d = (s[i] - '0'); // 数値に変換
        for(int j=0; j<13; j++) {
          dp[i+1][(d*digit + j)%13] += dp[i][j];
          dp[i+1][(d*digit + j)%13] %= mod;
        }
    }

    // DPテーブル出力
    // for (int i=0; i<=n; i++) {
    //   for (int j=0; j<13; j++) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    digit *= 10;
    digit %= 13;
  }

  cout << dp[n][5] << endl;
}