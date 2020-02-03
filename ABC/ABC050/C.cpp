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
int main() {
    int64 n;
    cin >> n;
    vector<int64> a(n);
    for (int64 i=0; i<n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());
    vector<P> len(1, P(a[0], 0));
    for (const auto& ai : a) {
        if (len.back().first == ai) len.back().second++;
        else len.emplace_back(ai, 1);
    }

    if (n % 2 == 1 && len.back().first == 0 &&  len.back().second == 1) len.pop_back();
    bool f = all_of(len.begin(), len.end(), [](P p){return p.second == 2;});

    int ans = 0;
    if (f) {
        ans = 1;
        for (int i=0; i<n/2; i++) {
            ans *= 2;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}
