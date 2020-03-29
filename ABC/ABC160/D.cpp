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

void bfs(int i, const vector<vector<int>>& g, map<int,int>& d) {
    queue<P> q;
    q.emplace(i,0);
    vector<int> dist(g.size(), -1);

    int64 res = 0;
    while(!q.empty()) {
        int u,c;
        tie(u,c) = q.front(); q.pop();
        if (dist[u] >= 0) continue;
        dist[u] = c;
        d[c]++;
        for (auto v : g[u]) q.emplace(v, (c+1));
    }
}

int main() {
    int64 n,x,y;
    cin >> n >> x >> y;

    vector<vector<int>> g(n+1);
    for (int i=1; i<n; i++) {
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    g[y].push_back(x);
    g[x].push_back(y);

    vector<map<int,int>> d(n+1);
    for (int i=1; i<=n; i++) {
        bfs(i, g, d[i]);
    }

    for (int i=1; i<n; i++) {
        int ans = 0;
        for (int j=1; j<=n; j++) ans += d[j][i];
        cout << ans / 2 << endl;
    }
}