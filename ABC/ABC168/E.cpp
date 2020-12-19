//
// Created by zeronosu77108 on Dec 19, 2020.
//
#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;
using P = pair<long, long>;

long modpow(long n, long t, const int MOD) {
    long res = 1;
    while (t) {
        if (t&1) res*=n, res%=MOD;
        n *= n;
        n %= MOD;
        t /= 2;
    }
    return res;
}

const int MOD = 1'000'000'007;
int main() {
    int n;
    cin >> n;

    map<P, long> mp;
    long nzero = 0;
    for (int i=0; i<n; i++) {
        long a, b;
        cin >> a >> b;
        if (a==0 && b==0) {
            nzero++;
            continue;
        }

        long GCD = gcd(a, b);
        a/=GCD; b/=GCD;

        if (signbit(a) != signbit(b)) a=-abs(a), b=abs(b);
        else a=abs(a), b=abs(b);

        mp[{a, b}]++;
    }

    long ans = 1;
    map<P, bool> used;
    for (const auto& [p, c] : mp) {
        if (used[p] || mp[p]<=0) continue;
        used[{p.second, -p.first}] = true;

        const auto c2 = mp[{p.second, -p.first}];
        ans *= (modpow(2, c, MOD) + modpow(2, c2, MOD) - 1) % MOD;
        ans %= MOD;
    }
    ans--;
    ans += nzero;
    ans += MOD;
    ans %= MOD;

    cout << ans << endl;
}