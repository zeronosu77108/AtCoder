//
// Created by zeronosu77108 on Dec 29, 2020.
//
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using P = pair<int, int>;

int main() {
    long n;
    cin >> n;

    long ans = n*(n+1)*(n+2) / 6;

    // 全組合せから u-v が採用される範囲分引く
    // → 1,2,3,u と v,v+1,...,n までの範囲は u-v が採用される
    for (int i=0; i<n-1; i++) {
        long u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        ans -= (u * (n-v+1));
    }

    cout << ans << endl;
}