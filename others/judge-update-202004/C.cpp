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

int f(const int&x, const int&y, const int&z, const int&a, const int& b, const int& c) {
    if (x==a && y==b && z==c) return 1;
    int ans = 0;
    if (x != a) ans += f(x+1, y, z, a, b, c);
    if (x>=y+1 && y != b) ans += f(x, y+1, z, a, b, c);
    if (y>=z+1 && z != c) ans += f(x, y, z+1, a, b, c);
    return ans;
}

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    cout << f(0,0,0,a,b,c) << endl;
}