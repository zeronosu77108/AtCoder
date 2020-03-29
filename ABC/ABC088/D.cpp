#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using TP = tuple<int,int,int>;

int bfs(const int& h, const int& w, const vector<string>& s) {
    bool goal = false;
    int goalc = 0;
    queue<TP> q;
    q.emplace(0,0,1);
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    const vector<int> dx = {-1, +0, +1, +0};
    const vector<int> dy = {+0, +1, +0, -1};

    while(!q.empty()) {
        int x,y,c;
        tie(x,y,c) = q.front(); q.pop();
        if (visited[y][x]) continue;
        visited[y][x] = true;
        if (x == w-1 && y == h-1) {
            goal = true;
            goalc = c;
        }
        for (int i=0; i<4; i++) {
            int xi = x + dx[i];
            int yi = y + dy[i];
            if (xi < 0 || w <= xi) continue;
            if (yi < 0 || h <= yi) continue;
            if (s[yi][xi] == '#') continue;
            q.emplace(xi,yi,c+1);
        }
    }

    int cnt = 0;
    for (int i=0; i<h; i++)
        cnt += count(s[i].begin(), s[i].end(), '.');

    if (!goal) return -1;
    return cnt - goalc;
}

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];
    cout << bfs(h,w,s) << endl;
}