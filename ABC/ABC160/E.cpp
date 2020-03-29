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
using P = pair<int,int>;

int main() {
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    priority_queue<P> pq;

    for (int i=0; i<a; i++) {
        int p;
        cin >> p;
        pq.emplace(p, 1);
    }
    for (int i=0; i<b; i++) {
        int p;
        cin >> p;
        pq.emplace(p, 2);
    }
    for (int i=0; i<c; i++) {
        int p;
        cin >> p;
        pq.emplace(p, 0);
    }

    int n = x+y;
    int64 ans = 0;
    while(n > 0 && (x>0 || y>0)) {
        int p,c;
        tie(p,c) = pq.top(); pq.pop();
//        cout << n << " " << x << " " << y << " "  << p << " " << c << endl;
        if (c == 1 && x > 0) {
            ans += p;
            x--; n--;
        }
        if (c == 2 && y > 0) {
            ans += p;
            y--; n--;
        }
        if (c == 0) {
            ans += p;
            n--;
        }
//        debug(ans);
    }

    cout << ans << endl;
}