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

const int MOD = 998244353;
int main() {
    int n,k;
    cin >> n >> k;

    vector<pair<int,int>> lr;
    for (int i=0; i<k; i++) {
        int l,r;
        cin >> l >> r;
        lr.emplace_back(l,r);
    }

    vector<int64> csum(n+1, 0);
    csum[0] = 1;
    csum[1] = -1;
    for (int i=0; i<n; i++) {
        csum[i] %= MOD;
        csum[i+1] += csum[i];
        csum[i+1] %= MOD;
        for (int j=0; j<k; j++) {
            auto [l, r] = lr[j];
            if (i+l >= n) continue;
            csum[i+l] += csum[i];
            csum[min(n, i+r+1)] -= csum[i];
        }
    }
    if (csum[n-1] < 0) csum[n-1] += MOD;

    cout << csum[n-1] << endl;
}