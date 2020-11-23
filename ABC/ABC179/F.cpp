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

int main() {
    int64 n, q;
    cin >> n >> q;

    unordered_map<int64, set<int64>> rmp;
    unordered_map<int64, set<int64>> cmp;
    set<int64> r;
    set<int64> c;
    rmp[n].insert(n);
    cmp[n].insert(n);
    r.insert(n);
    c.insert(n);

    int64 ans = (n-2)*(n-2);
    for (int _=0; _<q; _++) {
        int64 t, x;
        cin >> t >> x;

        if (t==1) {
            auto it = r.lower_bound(x);
            const auto i = *rmp[*it].begin();
            ans -= i - 2;
            cmp[i].insert(x);
            c.insert(i);
        } else {
            auto it = c.lower_bound(x);
            const auto i = *cmp[*it].begin();
            ans -= i - 2;
            rmp[i].insert(x);
            r.insert(i);
        }
    }
    cout << ans << endl;
}