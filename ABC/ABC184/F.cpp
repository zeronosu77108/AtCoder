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

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    int64 n, t;
    cin >> n >> t;
    vector a1(min(20LL, n), 0LL);
    vector a2(max(0LL,n-20LL), 0LL);
    for (int i=0; i<min(20LL, n); i++) cin >> a1[i];
    for (int i=20; i<n; i++) cin >> a2[i-20];

    vector<int64> v1;
    for (int i=0; i<(1<<min(20LL, n)); i++) {
        int64 sum = 0;
        for (int j=0; j<min(20LL,n); j++) {
            if ((i>>j)&1) {
                sum += a1[j];
            }
        }
        v1.emplace_back(sum);
    }

    vector<int64> v2;
    for (int i=0; i<(1<<max(0LL, n-20LL)); i++) {
        int64 sum = 0;
        for (int j=0; j<max(0LL,n-20LL); j++) {
            if ((i>>j)&1) {
                sum += a2[j];
            }
        }
        v2.emplace_back(sum);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int64 ans = 0;
    for (auto vi : v1) {
        auto r = t - vi;
        if (r < 0) break;
        auto it = upper_bound(v2.begin(), v2.end(), r);
        if (it!=v2.begin()) it--;
        if (*it + vi <= t) ans = max(ans, *it+vi);

    }

    cout << ans << endl;
}