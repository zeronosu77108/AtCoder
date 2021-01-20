//
// Created by zeronosu77108 on Jan 20, 2021.
//
#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector s(n+1, vector(n+1, 1L));

    const int MOD = 1'000'000'007;
    for (int i=3; i<=n; i++) {
        for (int j=2; j<i; j++) {
            s[i][j] = s[i-1][j-1] + (j * s[i-1][j]) % MOD;
            s[i][j] %= MOD;
        }
    }

    cout << s[n][m] << endl;
}