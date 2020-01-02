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


int main() {
    int64 r,c,k,n;
    int64 ans = 0;
    cin >> r >> c >> k >> n;
    vector<int64> x(n+1);
    vector<int64> y(n+1);
    vector<int64> col(c+1,0);
    vector<int64> row(r+1, 0);
    vector<int64> ncol(n+1, 0);
    vector<int64> nrow(n+1, 0);

    for (int64 i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        col[y[i]]++;
        row[x[i]]++;
    }

    for (int64 i=1; i<=c; i++) ncol[col[i]]++;
    for (int64 i=1; i<=r; i++) nrow[row[i]]++;

    for (int64 i=0; i<=k; i++) {
        int64 j = k - i;
        ans += ncol[i] * nrow[j];
    }

    for (int64 i=0; i<n; i++) {
        if (col[y[i]] + row[x[i]] == k) ans--;
        if (col[y[i]] + row[x[i]] == k+1) ans++;
    }

    cout << ans << endl;
    return 0;
}
