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
    int64 n,m;
    cin >> n >> m;
    vector<vector<int64>> a(n, vector<int64> (m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> a[i][j];
    }

    int64 ans = -1;
    for (int i=0; i<m; i++) {
        for (int j=i+1; j<m; j++) {
            int64 tmp = 0;
            for (int k=0; k<n; k++) {
                tmp += max(a[k][i], a[k][j]);
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;

}