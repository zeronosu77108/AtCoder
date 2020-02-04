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
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    for (int _=sx; _<tx; _++) cout << 'R';
    for (int _=sy; _<ty; _++) cout << 'U';

//    cout << endl;

    cout << 'R';
    for (int _=ty; _>sy-1; _--) cout << 'D';
    for (int _=tx+1; _>sx; _--) cout << 'L';
    cout << 'U';

//    cout << endl;


    for (int _=sy; _<ty; _++) cout << 'U';
    for (int _=sx; _<tx; _++) cout << 'R';

//    cout << endl;


    cout << 'U';
    for (int _=tx; _>sx-1; _--) cout << 'L';
    for (int _=ty; _>sy-1; _--) cout << 'D';
    cout << 'R';
}