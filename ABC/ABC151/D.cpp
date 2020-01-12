#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;
typedef pair<int64,int64> P;

int64 dx[4]={1,0,-1,0};
int64 dy[4]={0,1,0,-1};

int64 bfs(int64 i, int64 j, const int64& h, const int64& w, const vector<string>& s) {
    int64 res = 0;
    vector<vector<int64>> d(h, vector<int64>(w,-1));
    queue<pair<P,int64>> q;
    q.emplace(P(i,j), 0);

    while(!q.empty()) {
        int64 x,y,c;
        P p;
        tie(p,c) = q.front(); q.pop();
        tie(y,x) = p;

        if (x<0 || w<=x) continue;
        if (y<0 || h<=y) continue;
        if (d[y][x] != -1) continue;
        if (s[y][x] != '.') continue;

        d[y][x] = c;
        res = max(res, c);
        for (int64 k=0; k < 4; k++) {
            int xi,yi;
            xi = x + dx[k];
            yi = y + dy[k];
            if (xi<0 || w<=xi) continue;
            if (yi<0 || h<=yi) continue;
            if (s[yi][xi] != '.') continue;
            q.emplace(P(yi,xi),c+1);
        }
    }
    return res;
}

int main() {
    int64 h,w;
    int64 ans = 0;
    cin >> h >> w;
    vector<string> s(h);
    for (int64 i=0; i<h; i++) cin >> s[i];

    for (int64 i=0; i<h; i++) {
        for (int64 j=0; j<w; j++) {
            if (s[i][j] == '.') {
                ans = max(ans, bfs(i, j, h, w, s));
            }
        }
    }

    cout << ans << endl;
}