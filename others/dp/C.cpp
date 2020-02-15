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
    int n;
    cin >> n;
    vector<int64> a(n+1);
    vector<int64> b(n+1);
    vector<int64> c(n+1);

    for (int64 i=1; i<=n; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<int64>> dp(3, vector<int64> (n+1, 0));

    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;

    for (int64 i=1; i<=n; i++) {
        dp[0][i] = a[i] + max(dp[1][i-1], dp[2][i-1]);
        dp[1][i] = b[i] + max(dp[0][i-1], dp[2][i-1]);
        dp[2][i] = c[i] + max(dp[0][i-1], dp[1][i-1]);
    }

    int64 ans;
    ans = max(dp[0][n], dp[1][n]);
    ans = max(ans, dp[2][n]);

    cout << ans << endl;
}