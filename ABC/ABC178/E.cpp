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
    int64 n;
    cin >> n;
    vector x(n, 0LL);
    vector y(n, 0LL);
    for (int i=0; i<n; i++) cin >> x[i] >> y[i];

//    debug(x);
//    debug(y);

    int64 _max1 = INT_MIN;
    int64 _min1 = INT_MAX;
    for (int i=0; i<n; i++) _max1 = max(_max1, x[i] - y[i]);
    for (int i=0; i<n; i++) _min1 = min(_min1, x[i] - y[i]);

    int64 _max2 = INT_MIN;
    int64 _min2 = INT_MAX;
    for (int i=0; i<n; i++) _max2 = max(_max2, x[i] + y[i]);
    for (int i=0; i<n; i++) _min2 = min(_min2, x[i] + y[i]);

    cout << max(_max1 - _min1, _max2 - _min2) << endl;

}