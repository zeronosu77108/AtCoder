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
    vector<int64> t(n);
    vector<int64> a(n);
    for (int64 i=0; i<n; i++) cin >> t[i] >> a[i];

    int64 tin = 1;
    int64 ain = 1;
    for (int64 i=0; i<n; i++) {
        int64 x = max( (tin+t[i]-1)/t[i], (ain+a[i]-1)/a[i]);
        tin = x*t[i];
        ain = x*a[i];
    }

    cout << tin + ain << endl;
}