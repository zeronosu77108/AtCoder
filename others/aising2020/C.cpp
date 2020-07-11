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
    int n;
    cin >> n;

    map<int64,int64> mp;
    for (int64 x=1; x*x<=n; x++) {
        for (int64 y=1; y*y<=n; y++) {
            for (int64 z=1; z*z<=n; z++) {
                int64 i = x*x + y*y + z*z + x*y + y*z + z*x;
                mp[i]++;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << mp[i] << endl;
    }
}