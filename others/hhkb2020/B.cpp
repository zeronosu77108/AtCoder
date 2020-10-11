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
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];

    int ans = 0;
    vector dx = {+1, 0};
    vector dy = {0, +1};

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#') continue;
            for (int k=0; k<2; k++) {
                const int xi = j + dx[k];
                const int yi = i + dy[k];
                if (xi<0 || w<=xi) continue;
                if (yi<0 || h<=yi) continue;
                if (s[yi][xi] == '.') ans++;
            }
        }
    }

    cout << ans << endl;
}