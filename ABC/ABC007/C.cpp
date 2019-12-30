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
typedef pair<int,int> P;


int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfs(const int r, const int c, const P start, const vector<string>& b, vector<vector<int>>& ans) {
    queue<pair<P,int>> q;
    q.emplace(start,0);

    while(!q.empty()) {
        auto current = q.front(); q.pop();
        int x,y;
        tie(x,y) = current.first;
        if (ans[y][x] != -1) continue;
        else ans[y][x] = current.second;

        for (int i=0; i<4; i++) {
            int xi = x+dx[i];
            int yi = y+dy[i];
            if (xi < 0 || xi > c) continue;
            if (yi < 0 || yi > r) continue;
            if (b[yi][xi] == '.')
                q.emplace(P(x+dx[i], y+dy[i]), current.second+1);
        }
    }
}

int main() {
    int r,c;
    cin >> r >> c;
    vector<string> b(r);
    vector<vector<int>> ans(r, vector<int>(c,-1));
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;

    for (int i=0; i<r; i++) cin >> b[i];

    bfs(r,c, P(sx-1,sy-1), b,ans);
    cout << ans[gx-1][gy-1] << endl;
}