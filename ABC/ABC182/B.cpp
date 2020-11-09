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
    int n;
    cin >> n;

    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];
    int _max = 0;
    int ans = 0;
    for (int i=2; i<=1000; i++) {
        int cnt = 0;
        for (const auto ai : a) {
            if (ai%i == 0) cnt++;
        }

        if (cnt > _max) {
            _max = cnt;
            ans = i;
        }
    }

    cout << ans << endl;
}