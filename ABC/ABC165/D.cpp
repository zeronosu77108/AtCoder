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
    int64 a,b,n;
    cin >> a >> b >> n;

//    int64 l = 0;
//    int64 r = n;
//    for (int i=0; i<10000; i++) {
//        int64 ll = (l+l+r)/3;
//        int64 rr = (l+r+r)/3;
//
////        cout << ll << " " << rr << " " << a*ll/b - a*(ll/b) << " " << (a*rr)/b - a*(rr/b) << endl;
//        if ((a*ll)/b - a*(ll/b) >= (a*rr)/b - a*(rr/b)) {
//            r = rr;
//        } else {
//            l = ll;
//        }
//    }
//
//    int64 ans = 0;
//    for (int64 i=max(0LL, l-100000); i<=min(n, r+100000); i++) {
//        ans = max(ans, a*i/b - a*(i/b));
//    }

    cout << (a*n)/b - a*(n/b) << endl;
}