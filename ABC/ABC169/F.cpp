//
// Created by zeronosu77108 on Dec 27, 2020.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    vector dp(s+1, 0L);
    dp[0] = 1;

    const int MOD = 998'244'353;
    for (int i=0; i<n; i++) {
        for (int j=s; j>=0; j--) {
            dp[j]*=2; dp[j]%=MOD;
            if (j < a[i]) continue;
            dp[j] += dp[j-a[i]];
            dp[j] %= MOD;
        }
    }

    cout << dp.back() << endl;
}