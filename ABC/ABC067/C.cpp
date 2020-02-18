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
    vector<int64> a(n);
    for (int64 i=0; i<n; i++) cin >> a[i];

    vector<int64> right(n+1,0);
    vector<int64> left(n+1,0);
    for (int i=0; i<n; i++) {
        left[i+1] = left[i] + a[i];
        right[n-i-1] = right[n-i] + a[n-i-1];
    }

    int64 ans = LONG_MAX;
    for (int i=1; i<n; i++) ans = min(ans, abs(right[i] - left[i]));
    cout << ans << endl;
    debug(left);
    debug(right);
}