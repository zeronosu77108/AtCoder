//
// Created by zeronosu77108 on Jan 17, 2021.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int l;
    cin >> l;

    vector b(l, 0);
    for (int i=0; i<l; i++) cin >> b[i];

    if (reduce(b.begin(), b.end(), 0, bit_xor{})) {
        cout << -1 << endl;
        return 0;
    }

    vector ans(l, 0);
    for (int i=1; i<l; i++) {
        ans[i] = ans[i-1] xor b[i-1];
    }

    for (const auto& i : ans) {
        cout << i << endl;
    }
}