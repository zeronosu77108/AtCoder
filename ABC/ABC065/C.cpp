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

const int MOD = 1e9 + 7;

int64 frac(int n) {
    int64 res = 1;
    for (int i=1; i<=n; i++) {
        res *= i;
        res %= MOD;
    }
    return res;
}

int main() {
    int n,m;
    cin >> n >> m;

    int64 ans = frac(n);
    ans *= frac(m);

    cerr << "ans : " << ans << endl;

    if (n == m) {
        ans *= 2;
    } else if (abs(n-m) > 1) {
        ans = 0;
    }

    ans %= MOD;
    cout << ans << endl;
}