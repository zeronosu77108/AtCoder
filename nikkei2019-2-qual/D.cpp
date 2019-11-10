#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct edge {
    long to,cost;
    edge(long _to, long _cost): to(_to), cost(_cost){}
};

vector<long long> dijkstra(long long n, long long s, vector<vector<edge>> g) {
    typedef pair<long long,long long> P;
    vector<long long> d(n+1,LONG_MAX);
    priority_queue<P, vector<P>,greater<P>> q;
    q.push(make_pair(0,s));
    d[s] = 0;

    while (! q.empty()) {
        long long cost,u;
        tie(cost,u) = q.top();
        q.pop();
        if (d[u] < cost) continue;
        for (auto e : g[u]) {
            if (d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost;
                q.push( P(d[e.to], e.to));
            }
        }
    }
    return d;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<edge>> g(n+1);

    for (int i=0; i<n-1; i++) {
        g[i+1].push_back(edge(i,0));
    }

    for (int i=0; i<m; i++) {
        int l,r,c;
        cin >> l >> r >> c;
        g[l].push_back(edge(r,c));
        g[r].push_back(edge(l,c));
    }

    vector<long long> ans =  dijkstra(n,1,g);
    if (ans[n] == LONG_MAX) ans[n] = -1;

    cout << ans[n] << endl;
}