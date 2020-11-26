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
    int n, k;
    cin >> n >> k;
    vector a(n, 0L);
    for (int i=0; i<n; i++) cin >> a[i];

    vector csum(n+1, 0L);
    for (int i=0; i<n; i++) csum[i+1] = csum[i] + a[i];


    map<int64, int64> mp;
    int64 ans = 0;
    queue<int> q;
    for (int i=0; i<=n; i++) {
        ans += mp[(csum[i]-i)%k]++;
        if (i+1 >= k) mp[(csum[i-k+1]-(i-k+1))%k]--;
    }

    cout << ans << endl;
}