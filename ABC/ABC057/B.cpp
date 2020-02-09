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

int64 dist(int64 x1, int64 y1, int64 x2, int64 y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int64 n,m;
    cin >> n >> m;
    vector<int64> a(n);
    vector<int64> b(n);
    vector<int64> c(m);
    vector<int64> d(m);
    for (int64 i=0; i<n; i++) cin >> a[i] >> b[i];
    for (int64 i=0; i<m; i++) cin >> c[i] >> d[i];


    for (int64 i=0; i<n; i++) {
        int64 ans = 0;
        int64 dist_min = LONG_MAX;
        for (int64 j=0; j<m; j++) {
            int64 dist1 = dist(a[i], b[i], c[j], d[j]);
            if (dist_min > dist1) {
                dist_min = dist1;
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }

}