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

    vector<pair<int,int>> xy;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        xy.emplace_back(x, y);
    }

    bool ans = false;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            // y - y1 = (y2-y1)/(x2-x1) * (x - x1)
            for (int k=0; k<n; k++) {
                if (i==k || j==k) continue;
                const auto [x1, y1] = xy[i];
                const auto [x2, y2] = xy[j];
                const auto [x3, y3] = xy[k];
                if ((y3-y1) / (long double)(x3-x1) == (y2-y1) / (long double)(x2 - x1)) {
                    ans = true;
                }
            }
        }
    }

    cout << (ans? "Yes" : "No") << endl;
}