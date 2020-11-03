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
    int n, x;
    cin >> n >> x;
    vector dp(n, vector(n, 0));

    for (int i=0; i<n; i++) cin >> dp[0][i];

    int64 ans = accumulate(dp[0].begin(), dp[0].end(), 0LL);
    for (int i=1; i<n; i++) {
        for (int j=0; j<n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[0][(j-i+n)%n]);
        }
        ans = min(ans, i*x + accumulate(dp[i].begin(), dp[i].end(), 0LL));
    }

    cout << ans << endl;
}