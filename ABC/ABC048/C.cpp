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
    int n,x;
    int64 ans = 0;
    cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n-1; i++) {
        if (a[i] + a[i+1] > x) {
            int balance = a[i] + a[i+1] - x;
            ans += balance;
            a[i+1] = max(0, a[i+1] - balance);
        }
    }

    cout << ans << endl;
}