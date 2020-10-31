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
    int64 n, k;
    cin >> n >> k;

    int64 ans = 0;
    for (int64 i=2*n; i>=2; i--) {
        int64 diff = i - k;
        if (diff < 1) continue;
        if (abs(diff) > 2*n) continue;

        int64 cn;
        if (i > n) {
            cn = i+1 - (i-n)*2;
        } else {
            cn = i-1;
        }

        int64 cr;
        if (diff > n) {
            cr = diff+1 - (diff-n)*2;
        } else {
            cr = diff-1;
        }
        ans += cn * cr;
//        debug(ans);
    }

    cout << ans << endl;
}