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

int64 solve1(int64 n, int64 h, int64 a, int64 b, int64 c, int64 d, int64 e) {
    int64 ans = INT_MAX;
    for (int64 x=0; x<=n; x++) {
        for (int64 y=0; y<=(n-x); y++) {
            int64 benefit = h + b*x + d*y;
            int64 cost = a*x + c*y;
            if (benefit <= e*(n-x-y)) continue;
            ans = min(ans, cost);
        }
    }
    return ans;
}

int64 solve2(int64 n, int64 h, int64 a, int64 b, int64 c, int64 d, int64 e) {
    int64 ans = INT_MAX;
    for (int64 x=0; x<=n; x++) {
        int64 benefit = b*x + h;
        int64 cost = a*x;

        int64 y = (benefit - e*n + e*x) / -(d+e) + 1;
        y = max(0LL, y);
        if (x+y > n) continue;
        benefit += d*y;
        cost += c*y;

        if (benefit <= e*(n-x-y)) continue;
        ans = min(ans, cost);
    }
    return ans;
}

int main() {
    int64 n,h,a,b,c,d,e;
    int64 ans = LONG_MAX;
    cin >> n >> h;
    cin >> a >> b >> c >> d >> e;

    ans = solve1(n,h,a,b,c,d,e);

    cout << ans << endl;
}