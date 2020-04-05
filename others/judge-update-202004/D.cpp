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

int f(const int& n, vector<int64>& a, const int& s) {
    int64 l = -1;
    int64 r = n-1;
    while(l+1 < r) {
        int64 m = (l+r) / 2;
        if (gcd(a[m], s) == 1)
            r = m;
        else
            l = m;
    }
    return r+1;
}

int main() {
    int64 n,q;
    cin >> n >> q;
    vector<int64> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=1; i<n; i++) a[i] = gcd(a[i], a[i-1]);
    debug(a);
    for (int i=0; i<q; i++) {
        int64 s;
        cin >> s;

        if (gcd(s, a[n-1]) != 1) {
            cout << gcd(s, a[n-1]) << endl;
            continue;
        }


        cout << f(n,a,s) << endl;
    }
}