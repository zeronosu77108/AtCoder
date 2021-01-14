//
// Created by zeronosu77108 on Jan 14, 2021.
//
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
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

const int MOD = 1'000'000'007;
void bfs(const int& a, const vector<vector<int>>& g, vector<int>& ans) {
    vector dist(g.size()+1, optional<long>());
    queue<pair<int,int>> q;
    q.emplace(a, 0);
    dist[a] = 0;

    while (!q.empty()) {
        const auto [v, d] = q.front(); q.pop();
        
        for (const auto& u : g[v]) {
            if (!dist[u]) {
                dist[u] = d+1;
                q.emplace(u, d+1);
            }
            else if (dist[u].value() <= d) continue;
            ans[u] += ans[v];
            ans[u] %= MOD;
        }
    }
}

int main() {
    int n, a, b, m;
    cin >> n >> a >> b >> m;

    vector g(n+1, vector<int>());
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    vector ans(n+1, 0);
    ans[a] = 1;

    bfs(a, g, ans);

    cout << ans[b] % MOD << endl;
}
