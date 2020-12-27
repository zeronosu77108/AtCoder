//
// Created by zeronosu77108 on Dec 27, 2020.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(const int& s, vector<vector<int>>& g) {
    queue<pair<int,int>> q;
    q.emplace(s, 0);

    vector dist(g.size()+1, INT_MAX);
    while(!q.empty()) {
        auto [v, c] = q.front(); q.pop();
        if (dist[v] <= c) continue;
        dist[v] = c;

        for (const auto& u : g[v]) {
            q.emplace(u, c+1);
        }
    }

    return dist;
}

int main() {
    int n, t, a;
    cin >> n >> t >> a;

    vector g(n+1, vector<int>());
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    vector td = bfs(t, g);
    vector ad = bfs(a, g);

    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (td[i] >= ad[i]) continue;
        ans = max(ans, ad[i] - 1);
    }

    cout << ans << endl;
}