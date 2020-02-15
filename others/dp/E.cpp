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
    int64 n,ww;
    cin >> n >> ww;
    vector<int64> w(n);
    vector<int64> v(n);
    for (int i=0; i<n; i++) cin >> w[i] >> v[i];

    int64 v_max = -1;
    for (int i=0; i<n; i++) v_max = max(v_max, v[i]);
    v_max *= n;

    vector<int64> dp(v_max+1, INT_MAX);
    dp[0] = 0;

    for (int i=0; i<n; i++) {
        for (int j=v_max; j-v[i]>=0; j--) {
            dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
        }
    }

    int ans = INT_MAX;
    for (int i=0; i<=v_max; i++) {
        if (dp[i] <= ww) ans = i;
    }
    cout << ans << endl;
}