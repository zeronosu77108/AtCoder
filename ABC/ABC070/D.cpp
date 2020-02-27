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

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;
using P = pair<int64,int64>;
using V = vector<P>;

vector<int64> bfs(const int& n, const int& k, const vector<V>& g) {
    vector<int64> res(g.size()+1,-1);
    queue<P> q;
    q.emplace(k,0);
    
    while(!q.empty()) {
        int64 u,c;
        tie(u,c) = q.front(); q.pop();
        if (res[u] > 0) continue;
        res[u] = c;
        for (auto p : g[u]) {
            int64 v,d;
            tie(v,d) = p;
            q.emplace(v, c+d);
        }
    }
    return res;
}


int main() {
    int n;
    cin >> n;
    vector<V> g(n+1);
    
    for (int i=0; i<n-1; i++) {
        int64 a,b,c;
        cin >> a >> b >> c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }


    int64 q,k;
    cin >> q >> k;

    vector<int64> kdist = bfs(n,k,g);

    for (int i=0; i<q; i++) {
        int64 x,y;
        cin >> x >> y;
        cout << kdist[x] + kdist[y] << endl;
    }
}
