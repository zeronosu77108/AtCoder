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
    int r,c,k;
    cin >> r >> c >> k;
    vector dp(4, vector(r+1, vector(c+1, 0LL)));
    vector rc(r+1, vector(c+1,0LL));
    for (int i=0; i<k; i++) {
        int r,c,v;
        cin >> r >> c >> v;
        rc[r][c] = v;
    }

    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            for (int k=0; k<4; k++) dp[0][i][j] = max(dp[0][i][j], dp[k][i-1][j]);
            for (int k=0; k<4; k++) dp[k][i][j] = max(dp[k][i][j], dp[k][i][j-1]);

            for (int k=0; k<4; k++) dp[1][i][j] = max(dp[1][i][j], dp[k][i-1][j] + rc[i][j]);
            for (int k=0; k<3; k++) dp[k+1][i][j] = max(dp[k+1][i][j], dp[k][i][j-1] + rc[i][j]);
        }
    }

    cout << max({dp[0][r][c], dp[1][r][c], dp[2][r][c], dp[3][r][c]}) << endl;
}