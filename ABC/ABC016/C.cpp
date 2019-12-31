#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;
typedef pair<int,int> P;

int bfs(int i, int n, const vector<vector<int>>& g) {
    queue<P> q;
    vector<int> res(n+1,-1);
    q.push(P(i,0));

    while(!q.empty()) {
        int u,b;
        tie(u,b) = q.front(); q.pop();
        if (res[u] != -1) continue;
        res[u] = b;
        if (b > 2) continue;
        for (const auto v : g[u]) {
            q.emplace(v,b+1);
        }
    }
    int cnt = 0;
    for (auto r : res) if (r == 2) cnt++;
    return cnt;
}


int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);

    for (int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        vector<bool> used(n+1,false);
        cout << bfs(i,n, g) << endl;
    }
}