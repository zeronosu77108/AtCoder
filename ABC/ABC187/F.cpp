//
// Created by zeronosu77108 on Jan 4, 2021.
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
    int n, m;
    cin >> n >> m;

    vector g(n, vector(n, false));
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = g[b][a] = true;
    }

    vector dp(1<<n, LONG_MAX/3);
    dp[0] = 0;
    for (int i=1; i<1<<n; i++) {
        bool f = true;
        for (int j=0; j<n; j++) {
            if ((i>>j&1) == 0) continue;
            for (int k=j+1; k<n; k++) {
                if ((i>>k&1) == 0) continue;
                if (!g[j][k]) f = false;
            }
            if (!f) break;
        }
        if (f) dp[i] = 1;
    }

    for (int i=1; i<1<<n; i++) {
        for (int j=i; j>0; j=(j-1)&i) {
            dp[i] = min(dp[i], dp[i-j] + dp[j]);
        }
    }

    cout << dp.back() << endl;
}