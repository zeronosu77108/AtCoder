#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, const vector<vector<int>>& g, vector<bool>& visited) {
    if (visited[u]) return;
    visited[u] = true;
    for (auto v : g[u]) {
        if (visited[v]) continue;
        dfs(v, g, visited);
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for (int i=0; i<m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;
    vector<bool> visited(n+1,false);
    for (int i=1; i<=n; i++) {
        if (visited[i]) continue;
        ans++;
        dfs(i,g,visited);
    }

    cout << ans << endl;
}