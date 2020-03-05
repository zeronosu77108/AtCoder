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
    int n,m;
    cin >> n >> m;
    vector<int64> p(n+1,0);
    for (int i=1; i<=n; i++) cin >> p[i];

    vector<int64> pp;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            pp.push_back(p[i] + p[j]);
        }
    }

    sort(pp.begin(), pp.end());
    
    int64 ans = 0;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            int64 rest = m - p[i] - p[j];
            auto it = lower_bound(pp.begin(), pp.end(), rest);
            if (it == pp.end()) it--;
            if (it!=pp.begin() && p[i] + p[j] + *it > m) it--;
            int64 sum = p[i] + p[j] + *it;
            if (sum <= m) 
                ans = max(ans, sum);
        }
    }

    cout << ans << endl;
}
