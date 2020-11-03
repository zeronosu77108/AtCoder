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
    int n;
    cin >> n;
    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];
    map<int, int> mp;
    for (int i=0; i<n; i++) mp[a[i]] = i;

    set<int64> s;
    s.insert(-1);
    s.insert(n);

    int64 ans = 0;
    for (auto [c, i] : mp) {
        auto it = s.upper_bound(i);
        int64 up = *it - i;
        it--;
        int64 down = i - *it;

        ans += c * up * down;
        s.insert(i);
    }

    cout << ans << endl;
}