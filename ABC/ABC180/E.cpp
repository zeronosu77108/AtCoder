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
using TP = tuple<int64,int64,int64>;

int main() {
    int n;
    cin >> n;
    vector<TP> xyz;
    for (int i=0; i<n; i++) {
        int64 x, y, z;
        cin >> x >> y >> z;
        xyz.emplace_back(x, y, z);
    }

    vector dp(n, vector<int64>(1<<n, LONG_MAX));
    dp[0][1] = 0;

    auto dist = [&](int i, int j){
        return
        abs(get<0>(xyz[i]) - get<0>(xyz[j])) +
        abs(get<1>(xyz[i]) - get<1>(xyz[j])) +
        max(0LL, get<2>(xyz[i]) - get<2>(xyz[j]));
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1 << n; j++) {
            if (dp[i][j] >= LONG_MAX) continue;
            for (int k = 0; k < n; k++) {
                auto &d = dp[k][j | (1 << k)];
                d = min(d, dp[i][j] + dist(i, k));
            }
        }
    }

    cout << dp[0][(1<<n)-1] << endl;
}