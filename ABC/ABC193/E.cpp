//
// Created by zeronosu77108 on Feb 27, 2021.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}


template<class T> std::tuple<T,T,T> ext_euclid(T a, T b) {
    if (b==0) return {1, 0, a};
    const auto&& [x, y, g] = ext_euclid(b, a%b);
    return {y, x-a/b*y, g};
}

/**
 * Chinese remainder theorem（中国剰余定理）
 * @param am 連立合同式  z ≡ x (mod m1) : (x, m1)
 * @return (z, m) x ≡ z (mod m)
 */
std::pair<std::optional<long>, std::optional<long>> crt(const std::vector<std::pair<long, long>>& am) {
    long r = 0, n = 1;
    for (const auto& [a, m] : am) {
        const auto&& [x, y, d] = ext_euclid(n, m); // x is inv of n/d (mod. m/d)
        if ((a - r) % d != 0) return {std::nullopt, std::nullopt};

        long tmp = (a - r) / d * x % (m/d);
        r += n * tmp;
        n *= m / d;
    }
    return {(r%n+n)%n, n};
}


int main() {
    int t;
    cin >> t;

    for (int _=0; _<t; _++) {
        long x, y, p, q;
        cin >> x >> y >> p >> q;

        long ans = LONG_MAX;
        for (int i=0; i<y; i++) {
            const auto [a, b] = crt({{x+i, 2*(x+y)}, {p, p+q}});
            if (a) ans = min(ans, a.value());
        }

        for (int i=0; i<q; i++) {
            const auto [a, b] = crt({{x, 2*(x+y)}, {p+i, p+q}});
            if (a) ans = min(ans, a.value());
        }

        if (ans == LONG_MAX) cout << "infinity" << endl;
        else cout << ans << endl;
    }
}