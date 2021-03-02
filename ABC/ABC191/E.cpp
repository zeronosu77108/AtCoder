//
// Created by zeronosu77108 on Feb 6, 2021.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

using P = pair<long, long>;

vector<long> dijkstra(long n, long s, vector<vector<P>> g) {
    vector<long> d(n+1,INT_MAX);
    priority_queue<P, vector<P>,greater<>> q;
    q.emplace(0,s);
    d[s] = 0;

    while (! q.empty()) {
        const auto [cost, u] = q.top(); q.pop();
        if (d[u] < cost) continue;

        for (auto [e, c] : g[u]) {
            if (e == s) { d[n] = min(d[n], d[u] + c); }
            else if (d[e] > d[u] + c) {
                d[e] = d[u] + c;
                q.emplace( d[e], e);
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector g(n, vector<P>());
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
    }

    for (int i=0; i<n; i++) {
        const auto dist = dijkstra(n, i, g);
        if (dist[n] < INT_MAX) cout << dist[n] << endl;
        else cout << -1 << endl;
    }
}