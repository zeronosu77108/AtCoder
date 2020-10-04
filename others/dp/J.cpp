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

double dfs(const int& n, const int a, const int b, const int c, vector<vector<vector<double>>>& dp) {
    if (dp[a][b][c] >= 0) return dp[a][b][c];
    double res = 1;

    if (a>0) res += dfs(n, a-1, b, c, dp) * (a/(double)n);
    if (b>0) res += dfs(n, a+1, b-1, c, dp) * (b/(double)n);
    if (c>0) res += dfs(n, a, b+1, c-1, dp) * (c/(double)n);
    res /= 1 - ((double)(n-a-b-c) / n);
    return dp[a][b][c] = res;
}

int main() {
    int n;
    cin >> n;

    vector<int> cnt(4, 0);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    vector dp(n+1, vector(n+1, vector(n+1, -1.0)));
    dp[0][0][0] = 0;
    double ans = dfs(n, cnt[1], cnt[2], cnt[3], dp);
    cout << ans << endl;
}