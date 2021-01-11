//
// Created by zeronosu77108 on Jan 10, 2021.
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

using P = pair<long, long>;

int main() {
    int n, m;
    cin >> n >> m;

    vector a(n, 0L);
    for (int i=0; i<n; i++) cin >> a[i];

    vector g(n+1, vector<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    vector dp(n, LONG_MAX);
    long ans = LONG_MIN;
    for (int v=0; v<n; v++) {
        ans = max(ans, a[v] - dp[v]);
        for (const auto& u : g[v]) {
            dp[u] = min({dp[u], dp[v], a[v-1]});
        }
    }

    cout << ans << endl;
}