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
    int64 x, y, a, b;
    cin >> x >> y >> a >> b;

    int64 s = x;
    int64 exp = 0;
    while(s < y) {
        int64 t1 = s;
        int64 t2 = s;
        if (__builtin_mul_overflow(t1, a, &t1)) {
            if (__builtin_add_overflow(t2, b, &t2)) break;
            exp += (y-s-1) / b;
            break;
        } else if (__builtin_add_overflow(t2, b, &t2)) {
            break;
        } else {
            if (t1 < t2) {
                if (t1 >= y) break;
                s = t1;
                exp++;
            } else {
                exp += (y-s-1) / b;
                break;
            };
        }
//        debug(s);
    }

    cout << exp << endl;
}