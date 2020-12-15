#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    reverse(s.begin(), s.end());
    vector dp(2, vector<long>(n+1, INT_MAX));
    dp[0][0] = 0;

    for (int i=0; i<n; i++) {
        const auto c = s[i] - '0';
        dp[0][i+1] = min(dp[0][i], dp[1][i] + 1) + c;
        if (c != 0) dp[1][i+1] = min(dp[0][i] + (10-c), dp[1][i] + (9-c));  // 0は桁借りできない、桁借り連続は紙幣が1枚減る
    }

    cout << min(dp[0][n], dp[1][n]+1) << endl;
}