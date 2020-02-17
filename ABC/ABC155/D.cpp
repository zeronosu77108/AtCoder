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
using tu = tuple<int64,int64,int64>;
using P = pair<int64, int64>;

int main() {
    int64 n,k;
    cin >> n >> k;
    vector<int64> a(n);
    for (int64 i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    auto c = [&](int64 num) {
        int64 cnt = 0;

        for (int64 i=0; i<n; i++) {
            int64 l = -1;
            int64 r = n;
            while(l+1 < r) {
                int64 m = (l+r) / 2;
                if (a[i]*a[m] <= num) (a[i] < 0? r : l) = m;
                else (a[i] < 0? l : r) = m;
            }
            if (a[i] < 0) cnt += n - r;
            else cnt += l + 1;

            if (a[i] * a[i] <= num) cnt--;
        }
        return cnt;
    };

    int64 l = LONG_MIN / 2;
    int64 r = LONG_MAX / 2;
    while(l+1 < r) {
        int64 m = (l+r) / 2;
        if (c(m)/2 < k) l = m;
        else r = m;
    }
    cout << r << endl;
}
