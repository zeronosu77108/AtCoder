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

// 内分点（m:n）
template <class T> complex<T> internal_equinox(complex<T> a, complex<T> b, T m, T n) {
    const T x = (n*a.real() + m*b.real()) / (m+n);
    const T y = (n*a.imag() + m*b.imag()) / (m+n);
    return complex<T>(x, y);
}

int main() {
    long double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    complex<long double> p1(sx, sy);
    complex<long double> p2(gx, -gy);
    auto ans = internal_equinox(p1, p2, sy, gy);
    cout << ans.real() << endl;
}