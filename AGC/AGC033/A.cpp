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

int bfs(queue<P> q, const int& h, const int& w, vector<string>& a) {
    int res = 0;
    bool f = true;
    const vector dx = {-1, 0, +1, 0};
    const vector dy = {0, +1, 0, -1};

    while(f) {
        f = false;
        queue<P> tmp;
        while(!q.empty()) {
            auto[y, x] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                const int xi = x + dx[i];
                const int yi = y + dy[i];
                if (xi < 0 || w <= xi) continue;
                if (yi < 0 || h <= yi) continue;
                if (a[yi][xi] == '#') continue;
                a[yi][xi] = '#';
                f = true;
                tmp.emplace(yi, xi);
            }
        }
        swap(q, tmp);
        if (f) res++;
    }
    return res;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i=0; i<h; i++) cin >> a[i];

    queue<P> q;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (a[i][j] == '.') continue;
            q.emplace(i, j);
        }
    }

    int ans = bfs(q, h, w, a);
    cout << ans << endl;
}