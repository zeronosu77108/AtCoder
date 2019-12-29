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
    int n,m;
    int ans = -1;
    cin >> n >> m;
    vector<int64> g(n);

    for (int i=0; i<m; i++) {
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x] |= 1<<y;
        g[y] |= 1<<x;
    }

    for (int i=0; i<n; i++) g[i] |= 1<<i;

    for (int i=1; i<(1<<n); i++) {
        bool f = true;
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (((i>>j) & 1) == 0) continue;
            cnt++;
            if ((i&g[j]) !=i) f = false;
        }
        if (f) ans = max(ans,cnt);
    }

    cout << ans << endl;
    return 0;
}