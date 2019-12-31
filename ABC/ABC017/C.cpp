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
    int64 n,m;
    int64 ans = 0;
    cin >> n >> m;

    vector<int64> csum(m+2,0);
    for (int64 i=0; i<n; i++) {
        int64 l,r,s;
        cin >> l >> r >> s;
        csum[l] += s;
        csum[r+1] -= s;
        ans += s;
    }

    bool f = true;
    int64 cmin = INT_MAX;
    for (int64 i=0; i<=m; i++) {
        if (i!=0) {
            if (csum[i]==0) f = false;
            cmin = min(cmin, csum[i]);
        }

        csum[i+1] += csum[i];
    }
    if (f) ans -= cmin;

    cout << ans << endl;
}