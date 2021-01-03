//
// Created by zeronosu77108 on Jan 2, 2021.
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
using P = pair<int, int>;
using Graph = vector<vector<int>>;

void dfs1(const int& v, const int& p, const Graph& g, vector<int>& par) {
    par[v] = p;

    for (const auto& u : g[v]) {
        if (u == p) continue;
        dfs1(u, v, g, par);
    }
}

void dfs2(const int& v, const int& p, long sum, const Graph& g, vector<long>& ans) {
    ans[v] += sum;

    for (const auto& u : g[v]) {
        if (u == p) continue;
        dfs2(u, v, ans[v], g, ans);
    }

}

int main() {
    int n;
    cin >> n;

    Graph g(n+1);
    vector<P> edge;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        edge.emplace_back(a, b);
    }

    vector par(n+1, -1);
    dfs1(1, -1, g, par);

    int q;
    cin >> q;
    vector ans(n+1, 0L);

    for (int _=0; _<q; _++) {
        long t, e, x;
        cin >> t >> e >> x;
        auto [a, b] = edge[e-1];
        if (t == 2) swap(a, b);

        if (par[b] == a) {
            ans[1] += x;
            ans[b] -= x;
        } else {
            ans [a] += x;
        }
    }


    dfs2(1, -1, 0, g, ans);

    for (int i=1; i<=n; i++) {
        cout << ans[i] << endl;
    }
}