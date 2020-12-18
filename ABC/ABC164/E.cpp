//
// Created by zeronosu77108 on Dec 18, 2020.
//
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;
using P = pair<long, long>;
using TP = tuple<long,long,long>;

vector<vector<long>> dijkstra(const long& n, const vector<vector<TP>>& g, const vector<P>& cd, long s, const long& smax) {
    priority_queue<TP, vector<TP>, greater<>> q;
    s = min(smax, s);
    q.emplace(0, 1, s);
    vector dist(n+1, vector<long>(smax+1, LONG_MAX/100));

    while(!q.empty()) {
        const auto [cost, v, s] = q.top(); q.pop();
        if (dist[v][s] <= cost) continue;
        dist[v][s] = cost;

        const auto& [c, d] = cd[v];
        if (s+c <= smax) q.emplace(cost+d, v, s+c);
        else q.emplace(cost+d, v, smax);

        for (const auto& [u, a, b] : g[v]) {
            const auto move_s = s - a;
            if (move_s < 0) continue;
            q.emplace(cost+b, u, move_s);
        }
    }
    return dist;
}

int main() {
    long n, m, s;
    cin >> n >> m >> s;

    vector g(n+1, vector<TP>());
    int amax = 0;
    for (long i=0; i<m; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        g[u].emplace_back(v, a, b);
        g[v].emplace_back(u, a, b);
        amax = max(amax, a);
    }

    vector cd(1, P(INT_MAX, INT_MAX));
    for (int i=0; i<n; i++) {
        int c, d;
        cin >> c >> d;
        cd.emplace_back(c, d);
    }

    long smax = amax * n;
    vector d = dijkstra(n, g, cd, s, smax);

    for (int i=2; i<=n; i++) {
        cout << *min_element(d[i].begin(), d[i].end()) << endl;
    }
}