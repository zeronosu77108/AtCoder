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
    int64 ans = 1;
    vector a(n,0LL);
    for (int i=0; i<n; i++) cin >> a[i];

    if (any_of(a.begin(), a.end(), [](const int64& x){return x == 0LL;})) {
        cout << 0 << endl;
        return 0;
    }

    for (int i=0; i<n; i++) {
        if (__builtin_mul_overflow(ans, a[i], &ans) || ans > 1000000000000000000LL) {
            ans = -1;
            break;
        }
    }

    cout << ans << endl;
}
