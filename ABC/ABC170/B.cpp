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
    int x,y;
    cin >> x >> y;
    bool ans = false;
    for (int i=0; i*2<=y; i++) {
        for (int j=0; j*4<=y; j++) {
            if (i*2 + j*4 > y) continue;
            if (i*2 + j*4 == y && i+j == x) ans = true;
        }
    }

    cout << (ans? "Yes" : "No") << endl;
}