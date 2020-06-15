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
    int x,n;
    cin >> x >> n;
    map<int,bool> mp;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        mp[p] = true;
    }

    int ans = 0;
    int sa = INT_MAX;
    for (int i=-100; i<110; i++) {
        if (mp[i]) continue;
        if (sa > abs(i - x)) {
            sa = abs(i-x);
            ans = i;
        }
    }

    cout << ans << endl;
}