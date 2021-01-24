//
// Created by zeronosu77108 on Jan 23, 2021.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    int n;
    cin >> n;

    vector dp(2, vector(n+1, 0L));
    dp[0][0] = dp[1][0] = 1;

    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;

        if (s == "AND") {
            dp[1][i] += dp[1][i-1];
            dp[0][i] += 2*dp[0][i-1] + dp[1][i-1];
        } else {
            dp[1][i] += dp[0][i-1] + 2*dp[1][i-1];
            dp[0][i] += dp[0][i-1];
        }
    }

    cout << dp[1][n] << endl;
}