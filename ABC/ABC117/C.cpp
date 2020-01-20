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
#define debug(v) {cout<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}


using int64 = long long;
using P = pair<int64,int64>;


int main() {
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i=0; i<m; i++) cin>>x[i];
    sort(x.begin(), x.end());

    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> diff(m-1);
    for (int i=0; i<m-1; i++) {
        diff[i] = abs(x[i] - x[i+1]);
    }

    sort(diff.rbegin(), diff.rend());
    int ans = accumulate(diff.begin(), diff.end(), 0);
    for (int i=0; i<n-1; i++) ans -= diff[i];

    cout << ans << endl;
}