//
// Created by zeronosu77108 on Dec 13, 2020.
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
    int n,m;
    cin >> n >> m;

    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];
    vector b(m, 0);
    for (int i=0; i<m; i++) cin >> b[i];


    vector dp(n+1, vector(m+1, 0L));
    for (int i=1; i<=n; i++) dp[i][0] = i;
    for (int i=1; i<=m; i++) dp[0][i] = i;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            if (a[i-1] == b[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
        }
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    cout << dp[n][m] << endl;
}