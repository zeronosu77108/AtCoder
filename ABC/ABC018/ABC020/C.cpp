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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool dfs(int i, int j, int64 n, const int& m, vector<vector<int64>>& ans, const int& h, const int& w, const int& t, const vector<string>& s) {
    if (ans[i][j] <= n) return false;
    ans[i][j] = n;

    if (s[i][j] == 'G') return ans[i][j] <= t;

    bool res = false;
    for (int k=0; k<4; k++) {
        int x = j + dx[k];
        int y = i + dy[k];
        if (x < 0 || w <= x) continue;
        if (y < 0 || h <= y) continue;
        res = res || dfs(y,x, n + (s[i][j]=='#'? m : 1), m, ans, h, w, t, s);
    }
    return res;
}

int main() {
    int h,w,t;
    cin >> h >> w >> t;
    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];
    int sx,sy,gx,gy;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == 'S') sy=i,sx=j;
            if (s[i][j] == 'G') gy=i,gx=j;
        }
    }

    int64 l = 1;
    int64 r = t+1;
    while(l+1 < r) {
        int64 m = (l+r)/2;
        vector<vector<int64>> ans(h, vector<int64>(w, LONG_MAX));
        if (dfs(sy, sx, 0, m, ans, h,w,t,s))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
}