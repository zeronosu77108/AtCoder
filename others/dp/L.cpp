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
    int n;
    cin >> n;

    vector a(n, 0LL);
    for (int i=0; i<n; i++) cin >> a[i];

    vector dp(n, vector(n, 0LL));
    for (int i=0; i<n; i++) dp[i][i] = a[i];

    for (int i=1; i<=n; i++) {
        for (int j=0; j<n; j++) {
            if (i+j >= n) break;
            dp[j][i+j] = max(a[j]-dp[j+1][i+j], a[i+j] - dp[j][i+j-1]);
        }
    }

    cout << dp[0][n-1] << endl;
}