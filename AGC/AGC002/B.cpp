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
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector ball(n, 1);
    vector red(n, 0);
    red[0] = 1;

    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        ball[x]--;
        ball[y]++;
        if (red[y] > 0) red[y]++;

        if (red[x] > 0) {
            red[x]--;
            red[y] = ball[y];
        }

    }

    int ans = count_if(red.begin(), red.end(), [](const int& x){return x>0; });
    cout << ans << endl;
}