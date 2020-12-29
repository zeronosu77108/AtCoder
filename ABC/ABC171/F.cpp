//
// Created by zeronosu77108 on Dec 29, 2020.
//
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1'000'000'007;

long modpow(long n, long t, const int MOD=1'000'000'007) {
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

int main() {
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();

    init_fact(k+n);

    // "of" 'o' を入れるとき'o'の前に入れても後ろに入れても変わらない → 前に入れるのは考えない
    // "of" 'f' を 'f' の前後でも同じ
    // → 一番後ろに何個入れるか。 後ろに入れる個数を i = 0..k で 26^i 種類。
    // → 他の場所は、 n+k-i-1箇所入れる場所があって、 n-1 箇所入れる場所を選ぶ。
    // 種類としては 挿入する位置の次の文字以外なので、25種類、k-i個

    long ans = 0;
    for (int i=0; i<=k; i++) {
        long t = nCr(n+k-i-1, n-1);
        t *= modpow(26, i); t%=MOD;
        t *= modpow(25, k-i); t%=MOD;
        ans += t;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;

    cout << ans << endl;
}