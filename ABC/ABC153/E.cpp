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
    int64 h, n;
    cin >> h >> n;
    vector<int64> a(n);
    vector<int64> b(n);
    int64 amax = -1;
    for (int64 i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        amax = max(amax, a[i]);
    }
    h += amax + 10;
    vector<int64> dp(h+1, INT_MAX);
    dp[0] = 0;

    for (int64 i=0; i < n; i++) {
        for (int64 j=1; j <=h; j++) {
            if (j - a[i] < 0) continue;
            dp[j] = min(dp[j], dp[j - a[i]] + b[i]);
        }
    }

    int64 ans = INT_MAX;
    for (int64 i=h- amax - 10; i<h; i++) {
        if (ans > dp[i]) {
            ans = min(ans, dp[i]);
        }
    }
    cout << ans << endl;
}