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

int64 gcd(int64 a, int64 b) { return b? gcd(b,a%b):a; };
int64 lcm(int64 a, int64 b) { return a/gcd(a,b)*b; };

int main() {
    int64 n;
    cin >> n;
    vector<int64> t(n);
    for (int i=0; i<n; i++) cin>>t[i];
    int64 ans = 1;

    for (int i=0; i<n; i++)
        ans = lcm(ans, t[i]);

    cout << ans << endl;
}
