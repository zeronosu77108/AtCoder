//
// Created by zeronosu77108 on Dec 29, 2020.
//
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1'000'000'007;

long modpow(long n, long t) {
    n %= MOD;
    long res = 1;
    while (t) {
        if (t&1) res*=n, res%=MOD;
        n *= n;
        n %= MOD;
        t >>= 1;
    }
    return res;
}

vector<long> fact, ifact;
void fact_init(int n) {
    fact.resize(n+1, 1);
    ifact.resize(n+1, 1);

    for (int i=1; i<=n; i++) fact[i] = (fact[i-1] * i) % MOD;

    ifact[n] = modpow(fact[n], MOD-2);
    for (int i=n; i>1; i--) ifact[i-1] = (ifact[i] * i) % MOD;
}

long nCr(int n, int r) {
    if (n < r) return 0;
    return ((fact[n] * ifact[r])%MOD * ifact[n-r]) % MOD;
}

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    fact_init(h+w);

    h--; w--;
    long ans = nCr((h-a)+b, b) * nCr(a + w - b, w-b);
    for (int i=b+1; i<=w; i++) {
        long v = nCr((h-a)+i, i);
        long r = nCr((h-a)+i-1, i-1);
        long v2 = nCr(a+w-i, w-i);
        ans += (v-r) * v2;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;

    cout << ans << endl;
}