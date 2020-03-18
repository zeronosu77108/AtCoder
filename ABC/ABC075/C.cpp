#include <iostream>
#include <vector>
#include <map>

using namespace std;

using graph = vector<vector<int>>;
using V = vector<int>;
using P = pair<int,int>;

void dfs(const int& u, const int& k, const int& n, const graph& g, V& ord, V& low, map<P,bool> mp) {
    low[u] = ord[u] = k;
    for (auto v : g[u]) {
        if (ord[v] == -1) {
            mp[P(u,v)] = true;
            mp[P(v,u)] = true;
            dfs(v, k+1, n, g, ord, low,mp);

            low[u] = min(low[u], low[v]);
        } else if (!mp[P(u,v)]) {
            low[u] = min(low[u], ord[v]);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    graph g(n+1);
    for (int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    map<P, bool> mp;
    vector<int> ord(n+1, -1);
    vector<int> low(n+1, 0);
    dfs(1,n,  0,g, ord, low,mp);

    int ans = 0;
    for (int u=1; u<=n; u++) {
        for (auto v : g[u]) {
            if (ord[u] < low[v]) ans++;
        }
    }
    cout << ans << endl;
}