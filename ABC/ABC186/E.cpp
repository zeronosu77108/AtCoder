//
// Created by zeronosu77108 on Dec 19, 2020.
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


long extGCD(long a, long b, long &x, long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

void solve() {
    long n, s, k;
    cin >> n >> s >> k;

    s = -s + n;
    long d = gcd(n, gcd(s, k));
    s/=d; n/=d; k/=d;

    if (gcd(k, n) != 1) {
        cout << -1 << endl;
        return;
    }

    long x, y;
    extGCD(n, k, x, y);
    long ans = (y * s) % n;
    if (ans < 0) ans += n;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int _=0; _<t; _++) solve();
}