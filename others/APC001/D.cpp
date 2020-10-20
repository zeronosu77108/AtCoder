#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <map>

using namespace std;

using int64 = long long;

map<int64,int64> dfs(int i, const vector<vector<int>>& g, const vector<int64>& a, vector<bool>& visited) {
    vector<int> s;
    s.emplace_back(i);
    map<int64,int64> res;
    res[a[i]]++;
    while(!empty(s)) {
        const auto v = s.back(); s.pop_back();
        visited[v] = true;
        for (auto u : g[v]) {
            if (visited[u]) continue;
            res[a[u]]++;
            s.push_back(u);
        }
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int64> a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    vector g(n, vector<int>());
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    int start = 0;
    {
        int64 t = 0;
        for (int i = 0; i < n; i++) {
            if (t < g[i].size()) {
                t = g[i].size();
                start = i;
            }
        }
    }

    priority_queue<int64, vector<int64>, greater<>> q;
    vector<bool> visited(n, false);
    for (const auto [i,c] : dfs(start, g, a, visited)) {
        for (int _=0; _<c; _++) q.emplace(i);
    }

    int64 ans = 0;
    for (int i=0; i<n; i++) {
        if (visited[i]) continue;
        bool f = true;
        for (auto [i,c] : dfs(i, g, a, visited)) {
            if (f) {
                if (q.empty()) {
                    cout << "Impossible" << endl;
                    return 0;
                }
                ans += q.top() + i;
                q.pop();
                c--;
                f = false;
            }

            for (int _=0; _<c; _++) q.emplace(i);
        }
    }

    cout << ans << endl;
}