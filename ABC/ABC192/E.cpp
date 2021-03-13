//
// Created by zeronosu77108 on Mar 13, 2021.
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

using int64 = long long;

template <class T> std::vector<std::optional<T>> dijkstra(int s, std::vector<std::vector<std::tuple<int, T, T>>> g) {
    using P = std::pair<int, T>;
    const int n = g.size();

    std::vector dist(n+1, std::optional<T>());
    std::priority_queue<P, std::vector<P>, std::greater<>> q;
    q.emplace(0, s);
    dist[s] = 0;

    while (!q.empty()) {
        const auto [c, v] = q.top(); q.pop();
        if (dist[v].value() < c) continue;

        for (const auto& [u, d, k] : g[v]) {
            const T cost = dist[v].value() + d;
            if (dist[u] && dist[u].value() <= cost) continue;
            dist[u] = cost;
            q.emplace(dist[u].value(), u);
        }
    }
    return dist;
}

int main() {
    using P = tuple<int, int64, int64>;
    int64 n, m, x, y;
    cin >> n >> m >> x >> y;
    vector g(n+1, vector<P>());

    for (int _=0; _<m; _++) {
        int64 a, b, t ,k;
        cin >> a >> b >> t >> k;
        g[a].emplace_back(b, t, k);
        g[b].emplace_back(a, t, k);
    }

    const auto dist = dijkstra(x, g);
    if (dist[y]) cout << dist[y].value() << endl;
    else cout << -1 << endl;
}


