//
// Created by zeronosu77108 on Jan 2, 2021.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<long,long,long>> xyz;
    for (int i=0; i<n; i++) {
        long x, y, z;
        cin >> x >> y >> z;
        xyz.emplace_back(x,y,z);
    }

    long ans = 0;
    for (int i=0; i<1<<3; i++) {
        vector<long> t;
        for (const auto& [x,y,z] : xyz) {
            long sum = 0;
            sum += (i>>0&1? x : -x);
            sum += (i>>1&1? y : -y);
            sum += (i>>2&1? z : -z);
            t.emplace_back(sum);
        }

        sort(t.rbegin(), t.rend());
        ans = max(ans, accumulate(t.begin(), t.begin()+m, 0L));
    }

    cout << ans << endl;
}