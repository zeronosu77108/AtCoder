#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;
typedef pair<int,int> P;

void warshall_floyd(const int n, vector<vector<int64>>& d) {
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main() {
    int n,m;
    int64 ans = INT_MAX;
    cin >> n >> m;
    vector<vector<int64>> d(n+1, vector<int64>(n+1,INT_MAX));

    for (int i=1; i<n; i++) d[i][i] = 0;

    for (int i=0; i<m; i++) {
        int a,b,t;
        cin >> a >> b >> t;
        d[a][b] = t;
        d[b][a] = t;
    }

    warshall_floyd(n, d);

    for (int i=1; i<=n; i++) {
        int64 res = -1;
        for (int j=1; j<=n; j++)
            res = max(res, d[i][j]);
        ans = min(ans, res);
    }

    cout << ans << endl;
}