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
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));

    for (int i=0; i<n; i++) {
        cin >> c[i];
        for (int j=0; j<m; j++) cin >> a[i][j];
    }

    int ans = INT_MAX;
    for (int i=0; i<1<<n; i++) {
        int cnt = 0;
        vector<int> at(m,0);
        for (int j=0; j<n; j++) {
            if (i>>j&1) {
                cnt += c[j];
                for (int k=0; k<m; k++) {
                    at[k] += a[j][k];
                }
            }
        }
        if (all_of(at.begin(), at.end(), [&](const int& a){return a>=x;})) {
            ans = min(ans, cnt);
        }
    }

    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
}