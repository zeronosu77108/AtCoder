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
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<int> amax(n,-1);
    vector<int> amin(n, INT_MAX);

    amax[n-1] = a[n-1];
    for (int i=1; i<n; i++) amax[n-1-i] = max(amax[n-i], a[n-1-i]);

    map<int,int> mp;
    for (int i=0; i<n; i++) {
        mp[amax[i] - a[i]]++;
    }

    int ans = 0;
    int _max = -1;
    for (const auto &item : mp) {
        if (item.first > _max) {
            _max = item.first;
            ans = item.second;
        }
    }

    cout << ans << endl;
}