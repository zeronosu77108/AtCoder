//
// Created by zeronosu77108 on Feb 11, 2021.
//
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
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    long double tx, ty, tr;
    cin >> tx >> ty >> tr;

    long d = 10000;
    long x = round(tx * d);
    long y = round(ty * d);
    long r = round(tr * d);

    long xl = (x-r > 0)? (x-r+d-1)/d*d : (x-r)/d*d;
    long xu = (x+r < 0)? (x+r-d+1)/d*d : (x+r)/d*d;

    long ans = 0;
    for (long i=xl; i<=xu; i+=d) {
        long t = r*r - (x-i)*(x-i);
        long yd = sqrt(t) - 1;
        while ((yd+1)*(yd+1) <= t) yd++;

        long yu = (y+yd < 0)? (y+yd-d+1)/d : (y+yd)/d;
        long yl = (y-yd > 0)? (y-yd+d-1)/d : (y-yd)/d;

        if (yu < yl) continue;
        ans += abs(yu - yl) + 1;
    }

    cout << ans << endl;
}
