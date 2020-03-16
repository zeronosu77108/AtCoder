#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

int main() {
    int n,m,r;
    cin >> n >> m >> r;
    vector<int> rs(r);
    for (int i=0; i<r; i++) cin >> rs[i];

    vector<vector<int64>> d(n+1, vector<int64>(n+1, INT_MAX));

    for (int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    sort(rs.begin(), rs.end());

    int64 ans = LONG_MAX;
    do {
        int64 dist = 0;
        for (int i=0; i<r-1; i++) {
            dist += d[rs[i]][rs[i+1]];
        }
        ans = min(ans, dist);
    } while(next_permutation(rs.begin(), rs.end()));

    cout << ans << endl;
}