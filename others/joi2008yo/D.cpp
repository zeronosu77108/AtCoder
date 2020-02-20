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
#define all(x) x.begin(),x.end()

using int64 = long long;
using P = pair<int64, int64>;

int main() {
    int m;
    cin >> m;
    vector<P> ser;
    for (int i=0; i<m; i++) {
        int x,y;
        cin >> x >> y;
        ser.emplace_back(x,y);
    }
    sort(all(ser));

    vector<P> str;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        str.emplace_back(x,y);
    }
    sort(all(str));


    P ans;
    for (int i=0; i<n; i++) {
        int slidex =  str[i].first - ser[0].first;
        int slidey =  str[i].second - ser[0].second;
    
        bool f = true;
        for (int j=1; j<m; j++) {
            int x = ser[j].first + slidex;
            int y = ser[j].second + slidey;
            auto it = lower_bound(all(str), P(x, y));
            if (it == str.end() || ((*it).first != x || (*it).second!= y)) {
                f = false;
                break;
            }
        }
        if(f) ans = P(slidex, slidey);
    }

    cout << ans.first << " " << ans.second << endl;
}
