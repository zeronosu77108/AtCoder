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
    int n, k;
    cin >> n >> k;
    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> dp(k+1, false);
    dp[0] = false;

    for (int i=1; i<=k; i++) {
        bool f1 = true;
        for (auto ai : a) {
            if (i < ai) continue;
            f1 &= dp[i - ai];
        }
        if (!f1) dp[i] = true;
    }

    cout << (dp[k]? "First" : "Second") << endl;
}