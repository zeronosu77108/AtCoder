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
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i=0; i<n; i++) cin >> h[i];
    vector<int64> dp(n,INT_MAX);

    dp[0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=1; j<=k; j++) {
            if (i+j >= n) break;
            dp[i+j] = min(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
        }
    }

    cout << dp[n-1] << endl;
}