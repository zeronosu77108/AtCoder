#include <iostream>
#include <vector>

using namespace std;

using int64 = long long;
using P = pair<int, int64>;

int main() {
    int n, m;
    cin >> n >> m;

    vector<P> sc;
    for (int i=0; i<m; i++) {
        string s;
        int64 c;
        cin >> s >> c;
        int t = 0;
        for (int j=0; j<n; j++) {
            if (s[j]=='Y') t |= (1<<j);
        }
        sc.emplace_back(t, c);
    }

    vector<int64> dp(1<<n, LONG_MAX/3);
    for (auto [s,c] : sc) dp[s] = c;
    dp[0] = 0;

    for (int i=0; i<m; i++) {
        const auto& [s, c] = sc[i];
        for (int j=0; j<(1<<n); j++) {
            auto& d = dp[j | s];
            d = min(d, dp[j] + c);
        }
    }

    int64 ans = dp[(1<<n)-1];
    if (ans>=LONG_MAX/3) ans = -1;
    cout << ans << endl;
}