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
    for (int i=0; i<n; i++) cin >> a[i];


    int64 l = 0;
    int64 r = a[0];
    for (int i=1; i<n; i++) r=max(r,a[i]);

    while(l+1 < r) {
        int64 m = (l+r)/2;

        int64 t = 0;
        for (int i=0; i<n; i++) {
            t += a[i] / m;
            if (a[i] % m == 0) t--;
            if (t > k) break;
        }

        if (t <= k) r = m;
        else l = m;
    }
    cout << r << endl;
}