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
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> c(h);
    for (int i=0; i<h; i++) cin >> c[i];

    int ans = 0;
    for (int i=0; i<(1<<h); i++) {
        for (int j=0; j<(1<<w); j++) {

            int cnt = 0;
            for (int l=0; l<h; l++) {
                if ((i>>l)&1) continue;
                for (int m=0; m<w; m++) {
                    if (j>>m&1) continue;
                    if (c[l][m] == '#') cnt++;
                }
            }
            if (cnt == k) ans++;
        }
    }

    cout << ans << endl;
}