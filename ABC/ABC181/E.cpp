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
    int n, m;
    cin >> n >> m;

    vector h(n, 0LL);
    for (int i=0; i<n; i++) cin >> h[i];
    vector w(m, 0LL);
    for (int i=0; i<m; i++) cin >> w[i];
    sort(h.begin(), h.end());
    sort(w.begin(), w.end());

    vector fv(n, 0LL);
    vector bv(n, 0LL);
    for (int i=0; i<n-1; i+=2) fv[i+1] = h[i+1] - h[i];
    for (int i=n-1; i>=1; i-=2) bv[i-1] = h[i] - h[i-1];

    for (int i=1; i<n; i++) fv[i] += fv[i-1];
    for (int i=n-1; i>=1; i--) bv[i-1] += bv[i];


    int64 ans = LONG_MAX;
    for (int i=0; i<m; i++) {
        auto it = lower_bound(h.begin(), h.end(), w[i]);
        if (it == h.end()) it--;
        int index = it - h.begin();
        int64 cost = fv[index - (index%2)] + bv[index - (index%2)] +abs(h[index - (index%2)] - w[i]);
        ans = min(ans, cost);
    }

    cout << ans << endl;
};