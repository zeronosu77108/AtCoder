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

int main() {
    int64 n,k;
    int64 ans = 0;
    cin >> n >> k;

    vector<P> ab;

    for (int64 i=0; i<n; i++) {
        int64 a,b;
        cin >> a >> b;
        ab.emplace_back(a,b);
    }

    sort(ab.begin(), ab.end());

    for (auto p : ab) {
        k -= p.second;
        if (k <= 0) {
            ans = p.first;
            break;
        }
    }

    cout << ans << endl;
}