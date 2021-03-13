//
// Created by zeronosu77108 on Mar 13, 2021.
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
template <class T>ostream &operator<<(ostream &o,const optional<T>&v){o<<(v? to_string(v.value()) : "-");return o;}
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;
using Edge = int;
using Graph = vector<vector<Edge>>;

template <class T> bool chmin(optional<T>& a, T b) { if(!a || a.value() > b) { a = b; return true; } return false; }
template <class T> bool chmax(optional<T>& a, T b) { if(!a || a.value() < b) { a = b; return true; } return false; }


vector<optional<int64>> bfs(int s, Graph& g) {
    const int n = g.size();
    vector dist(n+1, optional<int64>());
    queue<Edge> q;
    q.emplace(s);
    dist[s] = 0;

    while (!q.empty()) {
        const auto v = q.front(); q.pop();
        for (const auto& u : g[v]) {
            if (!chmin(dist[u], dist[v].value() + 1)) continue;
            q.emplace(u);
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector g(n+1, vector<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }


    int k;
    cin >> k;
    vector c(k, 0);
    for (int i=0; i<k; i++) cin >> c[i];
    vector dist(k, vector<optional<int64>>());
    for (int i=0; i<k; i++) dist[i] = bfs(c[i], g);


    vector dp(1<<k, vector(k, optional<int64>()));
    for (int i=0; i<k; i++) dp[1<<i][i] = 0;

    for (int i=0; i<1<<k; i++) {
        for (int j=0; j<k; j++) {
            if (!dp[i][j]) continue;

            for (int l=0; l<k; l++) {
                if (dist[j][c[l]]) chmin( dp[i|(1<<l)][l], dp[i][j].value() + dist[j][c[l]].value());
            }
        }
    }

    optional<int64> ans;
    for (int i=0; i<k; i++) {
        if (dp.back()[i]) chmin(ans, dp.back()[i].value());
    }

    cout << ans.value_or(-2) + 1 << endl;
}