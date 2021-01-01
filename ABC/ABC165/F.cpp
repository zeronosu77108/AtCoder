//
// Created by zeronosu77108 on Jan 1, 2021.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using Graph = vector<vector<int>>;

void dfs(const int& v, const int& p, const Graph& g, const vector<long>& a, vector<long>& ans, vector<long>& LIS) {
    auto it = lower_bound(LIS.begin(), LIS.end(), a[v]);
    const long pre = *it;
    *it = a[v];

    ans[v] = lower_bound(LIS.begin(), LIS.end(), LONG_MAX) - LIS.begin();

    for (const auto& u : g[v]) {
        if (p == u) continue;
        dfs(u, v, g, a, ans, LIS);
    }

    *it = pre;
}

int main() {
    long n;
    cin >> n;

    vector a(n+1, 0L);
    for (int i=1; i<=n; i++) cin >> a[i];

    Graph g(n+1);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    vector ans(n+1, 0L);
    vector<long> LIS(n+1, LONG_MAX);

    dfs(1, -1, g, a, ans, LIS);
    for (int i=1; i<=n; i++) {
        cout << ans[i] << endl;
    }
}