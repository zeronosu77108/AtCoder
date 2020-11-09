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
    string n;
    cin >> n;

    int k = n.size();

    int ans = INT_MAX;

    for (int i=0; i<(1<<k)-1; i++) {
        int sum = 0;
        for (int j=0; j<k; j++) {
            if (((i>>j)&1) == 0) {
                sum += (n[j] - '0');
            }
        }
        if (sum%3 == 0) ans = min(ans, __builtin_popcount(i));
    }

    if (ans >= INT_MAX) ans = -1;
    cout << ans << endl;
}