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
    int k;
    cin >> k;

    if (k%2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    int i = 7;
    int ans = 1;
    while(i != 0) {
        if (i%k == 0) break;
        i %= k;
        i *= 10;
        i += 7;
        ans++;
        if (ans > 1000000) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}