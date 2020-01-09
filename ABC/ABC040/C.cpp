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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    vector<int> dp(n+2,INT_MAX);
    dp[0] = 0;
    for (int i=0; i<n-1; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(a[i]-a[i+1]));
        if (i+2 < n)
            dp[i+2] = min(dp[i+2], dp[i] + abs(a[i]-a[i+2]));
    }

    cout << dp[n-1] << endl;
}