//
// Created by zeronosu77108 on Jan 14, 2021.
//
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

long LCS(const string& s1, const string& s2) {
    const int n = s1.size();
    const int m = s2.size();

    vector dp(n+1, vector(m+1, 0));

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s1[i-1] == s2[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }
    }

    return dp[n][m];
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    long ans = 0;
    for (int i=0; i<n; i++) {
        const auto s1 = s.substr(0, i);
        const auto s2 = s.substr(i);

        ans = max(ans, LCS(s1, s2));
    }

    cout << n - 2*ans << endl;
}