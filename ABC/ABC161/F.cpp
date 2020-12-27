//
// Created by zeronosu77108 on Dec 27, 2020.
//
#include <iostream>
#include <vector>

using namespace std;

// 約数列挙
template <class T> vector<T> enumDivisors(const T n, const bool sorted=false) {
    vector<T> res(1,1);

    for (long long i=2; i*i<=n; i++) {
        if (n%i==0) {
            res.push_back(i);
            if (i*i != n) res.push_back(n/i);
        }
    }

    if (n!=1) res.push_back(n);
    if (sorted) sort(res.begin(), res.end());
    return res;
}

int main() {
    long n;
    cin >> n;

    // n-k が k未満になるまで → n%k → n が kの倍数+1
    // n-1 の約数
    long ans = enumDivisors(n-1).size() - 1;

    // n/k は n の約数 → 全部試して良さそう
    for (const auto& i : enumDivisors(n)) {
        if (i==1) continue;
        long t = n;
        while(t%i==0) t/=i;
        if (t%i == 1) ans++;
    }

    cout << ans << endl;
}