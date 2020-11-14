#include <iostream>
#include <vector>

using namespace std;

long dfs(const int& v, vector<vector<int>>& g) {
    if (g[v].size() <= 0) {
        return 0;
    }


    vector<long> res;
    for (auto u : g[v]) {
        res.emplace_back(dfs(u, g));
    }

    long ret = 0;
    sort(res.rbegin(), res.rend());
    for (int i=0; i<res.size(); i++) {
        ret = max(ret, res[i]+i+1);
    }

    return ret;
}

int main() {
    int n;
    cin >> n;
    vector g(n+1, vector<int>());

    for (int i=2; i<=n; i++) {
        int a;
        cin >> a;
        g[a].push_back(i);
    }

    vector<long> cnt(n+1, -1);
    long ans = dfs(1, g);

    cout << ans << endl;
}