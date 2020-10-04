#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector g(n+1, vector<int>());
    vector<int> deg(n+1, 0);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        deg[y]++;
    }

    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (deg[i]==0) q.emplace(i);
    }

    vector<int> dp(n+1, 0);
    while(!q.empty()) {
        int v = q.front(); q.pop();

        for (auto u : g[v]) {
            deg[u]--;
            if (deg[u] == 0) q.emplace(u);
            dp[u] = max(dp[u], dp[v] + 1);
        }
    }

    int ans = 0;
    for (int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
}