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

    vector<int64> dp(ww+1, 0);

    for (int i=0; i<n; i++) {
        for (int64 j=ww; j-w[i]>=0; j--) {
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout << dp[ww] << endl;
}