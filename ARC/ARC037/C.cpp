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
    int64 n,k;
    cin >> n >> k;
    vector<int64> a(n);
    vector<int64> b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int64 l = 0;
    int64 r = LONG_MAX/3;
    while(l+1 < r) {
        int64 m = (l+r) / 2;
        int64 cnt = 0;
        for (int i=0; i<n; i++) {
            auto it = lower_bound(b.begin(), b.end(), (m+a[i]-1)/a[i]);
            cnt += it - b.begin();
        }

        if (cnt >= k) r = m;
        else l = m;
    }

    cout << l << endl;
}
