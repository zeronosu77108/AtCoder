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
    int d,n,m;
    cin >> d >> n >> m;
    vector<int64> dd(n,0);
    vector<int64> k(m);
    for (int i=1; i<n; i++) cin >> dd[i];
    for (int i=0; i<m; i++) cin >> k[i];
    sort(dd.begin(), dd.end());
    sort(k.begin(), k.end());

    debug(dd);
    debug(k);

    int64 ans = 0;
    for (auto ki : k) {
        debug(ans);
        auto it = lower_bound(dd.begin(), dd.end(), ki);
        if (it == dd.begin()) continue;

        if (it == dd.end()) {
            ans += min(abs(d-ki), abs(dd.back() - ki));
            continue;
        }
        ans += min(abs(*it-ki), abs(*(it-1)-ki));
    }


    cout << ans << endl;
}
