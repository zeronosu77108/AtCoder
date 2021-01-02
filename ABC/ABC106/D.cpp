//
// Created by zeronosu77108 on Jan 2, 2021.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector f(n+1, vector(n+1, 0));

    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        f[l][r]++;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        }
    }

    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;

        cout << f[r][r] - f[l-1][r] - f[r][l-1] + f[l-1][l-1] << endl;
    }
}