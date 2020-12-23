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

    vector a(n, 0L);
    vector b(n, 0L);
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long double  am, bm;
    if (n%2) am=a[n/2], bm=b[n/2];
    else am=(a[n/2-1]+a[n/2])/2.0, bm=(b[n/2-1]+b[n/2])/2.0;
    debug(am);
    debug(bm);
    debug(bm - am);

    if (n%2) {
        cout << (long)(bm - am + 1) << endl;
    } else {
        cout << (long)((bm - am)*2 + 1) << endl;
    }
}