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

const int MOD = 1000000007;
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i=0; i<h; i++) cin >> a[i];

    const vector dx = {-1,  0,  0, +1};
    const vector dy = { 0, +1, -1,  0};
    vector dp(h, vector<int>(w, 0));
    dp[0][0] = 1;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (a[i][j] == '#') continue;
            for (int k=0; k<4; k++) {
                const int xi = j + dx[k];
                const int yi = i + dy[k];
                if (xi<0 || w<=xi) continue;
                if (yi<0 || h<=yi) continue;
                dp[yi][xi] += dp[i][j];
                dp[yi][xi] %= MOD;
            }
        }
    }

    cout << dp[h-1][w-1] << endl;
}