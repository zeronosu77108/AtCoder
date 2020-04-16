#include <iostream>
#include <vector>
#include <map>

using namespace std;
using int64 = long long;
using V = vector<int>;
using VV = vector<V>;
using P = pair<int,int>;

void dfs(const int& u, const int& p, const int64& d, const VV& g,  map<P,int64>& edges, vector<int64>& dist) {
    if (dist[u] >= 0) return;
    dist[u] = d;

    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v,u,d+edges[P(u,v)], g, edges, dist);
    }

}

int main() {
    int n;
    cin >> n;

    VV g(n+1);
    map<P,int64> edges;
    for (int i=0; i<n-1; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[P(u,v)] = w;
        edges[P(v,u)] = w;
    }

    vector<int64> dist(n+1,-1);
    dfs(1, -1, 0, g, edges, dist);

    for (int i=1; i<=n; i++) {
        cout << dist[i] % 2 << endl;
    }
}