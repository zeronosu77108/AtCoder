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

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;



int main() {
    int n;
    cin >> n;
    vector<string> s(n);

    for (int i=0; i<n; i++) cin >> s[i];

    long double ans = 0;
    vector g(n, vector<int>());
    for (int i=0; i<n; i++) {
        queue<int> q;
        q.emplace(i);

        vector<bool> visited(n, false);
        int cnt = 0;
        while(!q.empty()) {
            const auto v = q.front(); q.pop();
            if (visited[v]) continue;
            visited[v] = true;
            cnt++;
            for (int u=0; u<n; u++) {
                if (v == u) continue;
                if (visited[u]) continue;
                if (s[u][v] == '1') {
                    q.emplace(u);
                }
            }
        }
        ans += 1 / (long double)cnt;
    }

    cout << ans << endl;
}