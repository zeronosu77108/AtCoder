//
// Created by zeronosu77108 on Dec 28, 2020.
//
#include <iostream>
#include <vector>

using namespace std;

vector<long> fact;
vector<long> ifact;

const int MOD = 1'000'000'007;
long modpow(long n, long t, const long MOD = 1'000'000'007) {
    long res = 1;
    while(t) {
        if (t%2) res*=n, res%=MOD;
        n *= n;
        n %= MOD;
        t >>= 1;
    }
    return res;
}

void init_fact(int n) {
    fact.resize(n+1, 1);
    ifact.resize(n+1, 1);

    for (int i=1; i<=n; i++) fact[i] = (fact[i-1] * i) % MOD;

    ifact[n] = modpow(fact[n], MOD-2);
    for (int i=n; i>1; i--) ifact[i-1] = (ifact[i] * i) % MOD;
}

long nCr(int n, int r) {
    if (n < r) return 0;
    return ((fact[n] * ifact[r])%MOD * ifact[n-r])%MOD;
}

long nPr(int n, int r) {
    if (n < r) return 0;
    return (fact[n] * ifact[n-r]) % MOD;
}


int main() {
    int n, m;
    cin >> n >> m;
    init_fact(m);

    // 包除する → nPr(m, n)^2 から 1個被る、2個被る...を引いていく
    // Σ (-1)^i * nCi * mPi i個選ぶようなやつ。
    // 他の組合せ (m-i)P(n-i) が2個
    long ans = nPr(m, n) * nPr(m, n); ans %= MOD;

    for (int i=1; i<=n; i++) {
        long t = nCr(n, i) * nPr(m, i); t%=MOD;
        t *= nPr(m-i, n-i); t%=MOD;
        t *= nPr(m-i, n-i); t%=MOD;

        if (i%2) ans -= t;
        else ans += t;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;

    cout << ans << endl;
}