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
    int w,h,n;
    cin >> w >> h >> n;
    int x1,y1,x2,y2;
    x1 = y1 = 0;
    x2 = w;
    y2 = h;

    for (int i=0; i<n; i++) {
        int x,y,a;
        cin >> x >> y >> a;
        switch(a){
            case 1:
                x1 = max(x1, x);
                break;
            case 2:
                x2 = min(x2, x);
                break;
            case 3:
                y1 = max(y1, y);
                break;
            case 4:
                y2 = min(y2, y);
                break;
        }
    }

    cout << max(0,x2-x1)*max(0,y2-y1) << endl;
}