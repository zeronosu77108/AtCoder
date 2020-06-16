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
    int64 s;
    cin >> s;

    int64 x2,y2,x3,y3;
    x2 = 1;
    y2 = 1e9;
    x3 = (s+y2-1) / y2;
    y3 = abs(s - y2*x3);

//    cout << abs(x2*y3 - y2*x3) << endl;

    cout << 0 << " " << 0 << " ";
    cout << x2 << " " << y2 << " ";
    cout << x3 << " " << y3 << endl;
}