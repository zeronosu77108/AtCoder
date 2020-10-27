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

bool ok(const int& h, const int& w, const vector<string>& a, const vector<vector<bool>>& visited) {
    bool res = true;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (a[i][j] == '.') continue;
            res &= visited[i][j];
        }
    }
    return res;
}

bool dfs(const int& x, const int& y, const int& h, const int& w, const vector<string>& a, vector<vector<bool>>& visited) {
    visited[y][x] = true;

    if (x+1==w && y+1==h) {
        return ok(h,w,a,visited);
    }
    const vector dx = {+1, 0};
    const vector dy = { 0,+1};

    bool res = false;
    for (int i=0; i<2; i++) {
        const int yi = y + dy[i];
        const int xi = x + dx[i];
        if (xi<0 || w<=xi) continue;
        if (yi<0 || h<=yi) continue;
        if (a[yi][xi] == '.') continue;
        if (visited[yi][xi]) continue;
        res |= dfs(xi, yi, h, w, a, visited);
    }
    visited[y][x] = false;
    return res;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i=0; i<h; i++) cin >> a[i];

    vector visited(h, vector<bool>(w, false));
    bool ans = dfs(0, 0, h, w, a, visited);
    cout << (ans? "Possible" : "Impossible") << endl;
}