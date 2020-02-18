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
using P = pair<int,int>;

vector<int> bfs(const int& n, const vector<vector<int>>& g) {
    vector<int> res(n+1,-1);
    queue<P> q1;
    queue<P> q2;

    q1.emplace(1,0);
    q2.emplace(n,0);

    for (int i=0; i<n; i++) {
        while(!q1.empty() && q1.front().second == i) {
            int u,c;
            tie(u,c) = q1.front(); q1.pop();
            if (res[u] > 0) continue;
            res[u] = 1;
            for (auto v : g[u]) q1.emplace(v,c+1);
        }

        while(!q2.empty() && q2.front().second == i) {
            int u,c;
            tie(u,c) = q2.front(); q2.pop();
            if (res[u] > 0) continue;
            res[u] = 2;
            for (auto v : g[u]) q2.emplace(v,c+1);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    for (int i=0; i<n-1; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> color = bfs(n,g);
    map<int,int> mp;
    for (int i=1; i<=n; i++) mp[color[i]]++;
    debug(color);

    bool ans = mp[1] > mp[2];

    cout << (ans? "Fennec" : "Snuke") << endl;
}