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

int main() {
    int w,n,k;
    cin >> w >> n >> k;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<vector<V>> dp (n+1, vector<V>(w+1, V(k+1,0)));

    for (int i=1; i<=n; i++) cin>>a[i]>>b[i];


    for (int i=1; i<=n; i++) {
        for (int j=1; j<=w; j++) {
            for (int l=1; l<=k; l++) {
                dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l]);
                if (j - a[i] >= 0)
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-a[i]][l-1] + b[i]);
            }
        }

    }

    cout << dp[n][w][k] << endl;
}