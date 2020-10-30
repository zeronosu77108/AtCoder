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
#include <unordered_map>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int64 f(const int64 n, const int64& a, const int64 b, const int64& c, const int64& d, unordered_map<int64,int64>& mp) {
    if (n<=0 || mp[n]>0) return mp[n];
    int64 res = LONG_MAX;
    res = min(res, f(n/2, a, b, c, d, mp) + a + (n%2)*d);
    res = min(res, f((n+1)/2, a, b, c, d, mp) + a + ((n+1)/2*2-n)*d);
    res = min(res, f(n/3, a, b, c, d, mp) + b + (n%3)*d);
    res = min(res, f((n+2)/3, a, b, c, d, mp) + b + ((n+2)/3*3-n)*d);
    res = min(res, f(n/5, a, b, c, d, mp)  + c + (n%5)*d);
    res = min(res, f((n+4)/5, a, b, c, d, mp) + c + ((n+4)/5*5-n)*d);

    int64 mul;
    if (!__builtin_mul_overflow(n, d, &mul)) {
        res = min(res, mul);
    }

    return mp[n] = res;
}

void solve() {
    int64 n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    unordered_map<int64, int64> mp;
    mp[1] = d;
    cout << f(n,a,b,c,d,mp) << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
}