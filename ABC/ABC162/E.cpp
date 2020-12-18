//
// Created by zeronosu77108 on Dec 17, 2020.
//
#include <iostream>
#include <vector>

using namespace std;

long modpow(long n, long k, const long MOD) {
    long res = 1;
    while(k) {
        if (k&1) res*=n, res%=MOD;
        n *= n;
        n %= MOD;
        k /= 2;
    }
    return res;
}

const int MOD = 1'000'000'007;
int main() {
    int n, k;
    cin >> n >> k;

    long ans = 0;
    vector<long> p(k+1, 0);
    for (long i=k; i>=1; i--) {
        const auto c = k / i;

        p[i] = modpow(c, n, MOD);
        for (long j=i+i; j<=k; j+=i) p[i]-=p[j], p[i]%=MOD;
        if (p[i]<0) p[i]+=MOD;
        ans += i * p[i];
        ans %= MOD;
    }
    cout << ans << endl;
}