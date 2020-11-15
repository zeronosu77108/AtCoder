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
    int64 n;
    string s, t;
    cin >> n >> s >> t;

    int64 ans = 0;
    set<int64> ts;
    for (int64 i=0; i<n; i++) {
        if (t[i] == '1') ts.insert(i);
    }

    set<int64> ss;
    for (int64 i=0; i<n; i++) {
        if (s[i] == '1') {
            if (!ss.empty()) {
                ans += i - *ss.begin();
                ss.erase(ss.begin());
            } else if (*ts.begin() <= i) {
                ans += i - *ts.begin();
                ts.erase(ts.begin());
            } else {
                ss.insert(i);
            }
        }
    }

    if (!ts.empty() || !ss.empty()) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}