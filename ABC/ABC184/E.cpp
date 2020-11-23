#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;
using P = pair<int, int>;

void bfs(const P& start, const int& h, const int& w, const vector<string>& s, vector<vector<int>>& dist, map<char,vector<P>>& mp) {
    using TP = tuple<int, int, int>;
    queue<TP> q;
    q.emplace(0, start.first, start.second);

    const vector dx = {-1, 0,+1, 0};
    const vector dy = { 0,+1, 0,-1};

    unordered_map<char, bool> used;
    while(!q.empty()) {
        auto [d, y, x] = q.front(); q.pop();
        if (dist[y][x]>0 && dist[y][x] <= d) continue;
        dist[y][x] = d;

        if (!used[s[y][x]]) {
            used[s[y][x]] = true;
            for (const auto&[a, b] : mp[s[y][x]]) {
                if (a == y && b == x) continue;
                q.emplace(d + 1, a, b);
            }
        }


        for (int i=0; i<dx.size(); i++) {
            const auto xi = x + dx[i];
            const auto yi = y + dy[i];
            if (xi<0 || w<=xi) continue;
            if (yi<0 || h<=yi) continue;
            if (s[yi][xi] == '#') continue;
            q.emplace(d+1, yi, xi);
        }
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];


    map<char, vector<P>> mp;

    P start, goal;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == 'S') start = {i, j};
            if (s[i][j] == 'G') goal = {i, j};

            if (s[i][j] != '.' && s[i][j] != '#') {
                mp[s[i][j]].emplace_back(i, j);
            }
        }
    }

    vector dist(h, vector(w, -1));
    bfs(start, h, w, s, dist, mp);
//    debug(dist)

    cout << dist[goal.first][goal.second] << endl;
}