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
typedef vector<int> V;

const int mod = 1000000007;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int dfs(const int x, const int y, const int& h, const int& w,  vector<V>& dp, const vector<V>& p) {
    if (dp[y][x] != -1) return dp[y][x];

    int64 res = 1;
    for (int i=0; i<4; i++) {
        int xi = x + dx[i];
        int yi = y + dy[i];

        if (xi < 0 || xi >= w) continue;
        if (yi < 0 || yi >= h) continue;
        if (p[y][x] >= p[yi][xi]) continue;
        
        res += dfs(xi, yi, h, w, dp, p);
        res %= mod;
    }
    return dp[y][x] = res;
}


int main() {
    int h,w;
    int64 ans = 0;
    cin >> h >> w;
    vector<V> p(h, V(w));
    vector<V> dp(h, V(w,-1));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> p[i][j];
        }
    }

    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {
            ans += dfs(x, y, h, w, dp, p);
            ans %= mod;
        }
    }

    cout << ans << endl;
}