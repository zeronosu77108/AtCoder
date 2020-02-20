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
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
template <typename T1, typename T2>ostream &operator<<(ostream &o,const pair<T1,T2>&v){o<<"("<<v.first<<","<<v.second<<")";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}
#define all(x) x.begin(),x.end()



using int64 = long long;
using P = pair<int64, int64>;

int main() {
    int n;
    cin >> n;
    vector<P> points;

    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        points.emplace_back(x,y);
    }
    sort(points.begin(), points.end());

    double ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int x1,x2,y1,y2;
            tie(x1,y1) = points[i];
            tie(x2,y2) = points[j];
            
            int ym = abs(x1 - x2);
            int xm = abs(y1 - y2);

            auto it1 = lower_bound(all(points), P(x1+xm,y1+ym));
            if (it1 == points.end()) continue;
            if (*it1 != P(x1+xm, y1+ym)) continue;

            auto it2 = lower_bound(all(points), P(x2+xm,y2+ym));
            if (it2 == points.end()) continue;
            if (*it2 != P(x2+xm, y2+ym)) continue;

            int x3,x4,y3,y4;
            tie(x3,y3) = *it1;
            tie(x4,y4) = *it2;
            double d1 = sqrt((double)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            double d2 = sqrt((double)(x3-x4)*(x3-x4) + (y3-y4)*(y3-y4));
            
            // cerr << "square" << endl;
            // cerr << x1 << " " << y1 << endl;
            // cerr << x2 << " " << y2 << endl;
            // cerr << x3 << " " << y3 << endl;
            // cerr << x4 << " " << y4 << endl;
            // cerr << d1 << " " << d2 << endl;
            
            ans = max(ans, d1*d2);
        }
    }

    cout << (int)round(ans) << endl;
}

