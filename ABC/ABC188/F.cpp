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
#include <unordered_map>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using P = pair<long, long>;

long f(const long x, const long y, unordered_map<long,long>& mp) {
    if (x>=y) return abs(x-y);
    if (mp[y] > 0) return mp[y];

    auto& c = mp[y];
    c = abs(y-x);

    if (y%2) {
        c = min(c, f(x, (y+1)/2, mp) + 2);
        c = min(c, f(x, (y-1)/2, mp) + 2);
    } else {
        c = min(c, f(x, y/2, mp) + 1);
    }

    return c;
}

int main() {
    long x,y;
    cin >> x >> y;

    if (y <= x) {
        cout << x - y << endl;
        return 0;
    }

    unordered_map<long, long> mp;
    cout << f(x, y, mp) << endl;
}