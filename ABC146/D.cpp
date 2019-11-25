#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

void bfs(map<P,int>& mp, int &k, const int n, const Graph& g) {
    vector<bool> used(n+1,false);
    vector<int> c(n+1,-1);
    queue<int> q;
    q.push(1);
    used[1] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        int cc = 1;
        for (auto v : g[u] ) {
            if (used[v]) continue;
            used[v] = true;
            q.push(v);
            if (cc == c[u]) cc++;
            c[v] = mp[P(u,v)] = cc++;
        }
        k = max(k, cc-1);
    }
}

int main() {
    int n;
    int k = 0;
    cin >> n;

    Graph g(n+1);
    vector<P> edge;

    for (int i=0; i<n-1; i++) {
        int a,b;
        cin >> a >> b;
        if (a>b) swap(a,b);
        edge.push_back(P(a,b));
        g[a].push_back(b);
        g[b].push_back(a);
    }

    map<P,int> mp;
    bfs(mp, k, n, g);


    cout << k << endl;
    for (auto e : edge) {
        cout << mp[e] << endl;
    }
}