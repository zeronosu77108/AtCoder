//
// Created by zeronosu77108 on Jan 3, 2021.
//
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector a(n, vector(n, 0L));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    vector p(1<<n, 0L);
    for (int i=0; i<1<<n; i++) {
        for (int j=0; j<n; j++) {
            if ((i>>j&1) == 0) continue;
            for (int k=j+1; k<n; k++) {
                if ((i>>k&1) == 0) continue;
                p[i] += a[j][k];
            }
        }
    }

    vector<long> dp(1<<n, LONG_MIN/3);
    dp[0] = 0;
    for (int i=0; i<1<<n; i++) {
//        cerr << '\n' << bitset<16>(i) << endl;
        for (int j=i; j>0; j=(j-1)&i) {
//            cerr << bitset<16>(j) << endl;
            dp[i] = max(dp[i], dp[i^j] + p[j]);
        }
    }

    cout << dp.back() << endl;
}