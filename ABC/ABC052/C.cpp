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
using P = pair<int64,int64>;
const int MOD = 1000000007;

void diviser(int64 n, map<int64,int64>& mp) {
    for (int64 i=2; i*i<=n; i++) {
        while (n % i == 0) n/=i, mp[i]++;
        mp[i] %= MOD;
    }
    if (n != 1) mp[n]++;
}

int main() {
    int64 n;
    cin >> n;

    map<int64,int64> mp;
    for (int64 i=2; i<=n; i++) diviser(i,mp);

    int64 ans = 1;
    for (auto p : mp) {
        ans *= (p.second + 1);
        ans %= MOD;
    }

    cout << ans << endl;
}