//
// Created by zeronosu77108 on Dec 27, 2020.
//
#include <iostream>
#include <vector>

using namespace std;

vector<long> fact;
vector<long> ifact;

long modpow(long n, long t, long MOD = 1'000'000'007) {
    long res = 1;
    while(t) {
        if (t&1) res*=n, res%=MOD;
        n *= n;
        n %= MOD;
        t >>= 1;
    }
    return res;
}



const int MOD = 1'000'000'007;
void fact_init(int n) {
    fact.resize(n+1, 1);
    ifact.resize(n+1, 0);

    for (int i=1; i<=n; i++) fact[i] = (fact[i-1] * i) % MOD;

    ifact[n] = modpow(fact[n], MOD-2, MOD);
    for (int i=n; i>=1; i--) ifact[i-1] = (ifact[i] * i) % MOD;
}

long nCr(long n, long r) {
    if (n < r) return 0;
    return ((fact[n] * ifact[r]) %MOD * ifact[n-r]) %MOD;
}

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    fact_init(r2+c2+1);

    long ans = 0;
    for (int i=c1+1; i<=c2+1; i++) {
        ans += nCr(r2+i, i) - nCr(r1+i-1, i);
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;

    cout << ans << endl;
}
