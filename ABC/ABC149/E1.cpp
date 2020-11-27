#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <complex>


using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

using int64 = long long;

template <typename T> void dft(vector<complex<T>>& v, const int& n, const bool inv = false) {
    if (n == 1) return;
    vector<complex<T>> f0(n/2);
    vector<complex<T>> f1(n/2);

    for (int i=0; i<n; i++) {
        if (i%2 == 0) f0[i/2] = v[i];
        if (i%2 == 1) f1[i/2] = v[i];
    }

    dft(f0, n/2, inv);
    dft(f1, n/2, inv);
    const auto t = inv? -1 : 1;
    const auto zeta = complex<T>(cos(t*2*M_PI/n), sin(t*2*M_PI/n));
    auto pow_zeta = complex<T>(1, 0);
    for (int i=0; i<n; i++) {
        v[i] = f0[i%(n/2)] + pow_zeta * f1[i%(n/2)];
        pow_zeta *= zeta;
    }
}

template <typename T> void multiply(vector<T>& g, const vector<T>& h) {
    int n = g.size() + h.size() - 1;
    int t = 1;
    while(t<n) t*=2;

    vector<complex<T>> gg(t);
    vector<complex<T>> hh(t);
    for (int i=0; i<g.size(); i++) gg[i] = complex<T>(g[i], 0);
    for (int i=0; i<h.size(); i++) hh[i] = complex<T>(h[i], 0);

    dft(gg, t);
    dft(hh, t);

    for (int i=0; i<t; i++) gg[i] *= hh[i];
    g.resize(n);
    dft(gg, t, true);
    for (int i=0; i<n; i++) g[i] = gg[i].real() / t;
}

int main() {
    int64 n,m;
    cin >> n >> m;

    constexpr auto _max = 200'001;
    vector<long double> f0(_max);
    vector<long double> f1(_max);

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        f0[a]++; f1[a]++;
    }

    multiply(f0, f1);

    long ans = 0;
    long res = m;
    for (int i=_max; i>=0; i--) {
        const auto c = (long)(round(f0[i]));
        if (c<=0) continue;
        ans += i * min(res, c);
        res -= c;
        if (res <= 0) break;
    }
    cout << ans << endl;
}
// FFT する。 i になる組合せが分かる → 上から m 個足す