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
    vector<int> x(n);
    for (int i=0; i<n; i++) cin >> x[i];

    int ans = INT_MAX;
    for (int i=1; i<=100; i++) {
        int cnt = 0;
        for (int j=0; j<n; j++) {
            cnt += (i - x[j]) * (i - x[j]);
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;
}