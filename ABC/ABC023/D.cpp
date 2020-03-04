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
    int64 n;
    cin >> n;
    vector<int64> h(n);
    vector<int64> s(n);
    for (int64 i=0; i<n; i++) cin >> h[i] >> s[i];

    int64 l = 0;
    int64 r = LONG_MAX/5;
    while(l+1 < r) {
        int64 m = (l+r) / 2;
        bool f = true;
        vector<int64> used(n,0);
        for (int64 i=0; i<n; i++) {
            if (m - h[i] < 0) {
                f = false;
                break;
            }

            int64 d = (m - h[i]) / s[i];
            if (d >= n) continue;
            used[d]++;
        }

        for (int64 i=0; i<n-1; i++) used[i+1] += used[i];
        for (int64 i=0; i<n; i++) {
            if (used[i] > i+1) {
                f = false;
                break;
            }
        }

        if (f) r = m;
        else l = m;
    }

    cout << r << endl;
}
