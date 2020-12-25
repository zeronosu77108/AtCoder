#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;


template <typename T> bool chmax(T& a, const T&& b){if(a<=b){a=b; return true;} return false;}

const int MOD = 1'000'000'007;
long modpow(long n, long t) {
    long res = 1;
    while (t) {
        if (t&1) res*=n, res%=MOD;
        n *= n;
        n %= MOD;
        t /= 2;
    }
    return res;
}

int main() {
    long n,k;
    cin >> n >> k;
    vector a(n, 0L);
    for (int i=0; i<n; i++) cin >> a[i];

    const auto mod_mul = [&](long acc, long x){return (acc*x)%MOD;};
    bool all_of_minus = all_of(a.begin(), a.end(), [](const long& x){return x<0;});
    if (all_of_minus && k%2) {
        sort(a.rbegin(), a.rend());
        long ans = accumulate(a.begin(), a.begin()+k, 1L, mod_mul);
        if (ans<0) ans+=MOD;
        cout << ans << endl;
        return 0;
    }

    auto c = []( long x,  long y){ return abs(x) < abs(y);};
    sort(a.begin(), a.end(), c);

    long ans = accumulate(a.end()-k, a.end(), 1L, mod_mul);

    vector<long> kp, km;
    long cnt = 0;
    for (int i=0; i<k; i++) {
        if (a.back() < 0) {
            cnt++;
            km.emplace_back(a.back());
        }
        else kp.emplace_back(a.back());
        a.pop_back();
    }
    sort(kp.rbegin(), kp.rend());
    sort(km.begin(), km.end());


    vector<long> rp, rm;
    for (const auto& i : a) {
        if (i < 0) rm.emplace_back(i);
        else rp.emplace_back(i);
    }
    sort(rm.rbegin(), rm.rend());
    sort(rp.begin(), rp.end());



    // 負数になっている場合（cntが奇数）
    // 採用した正の絶対値最小 → 採用していない負の絶対値最大
    // 採用した負の絶対値最小 → 採用していない正の絶対値最大
    // rm/kp > rp/km なら rm/kp をする
    // rm*km > kp*rp
    if(cnt%2) {
        bool f1 = !km.empty() && !rp.empty();
        bool f2 = !kp.empty() && !rm.empty();
        if (f1 && f2) {
            if (rm.back() * km.back() > kp.back() * rp.back()) {
                ans *= rm.back();
                ans %= MOD;
                ans *= modpow(kp.back(), MOD - 2);
            } else {
                ans *= rp.back();
                ans %= MOD;
                ans *= modpow(km.back(), MOD - 2);
            }
        } else if (f1) {
            ans *= modpow(km.back(), MOD-2);
            ans %= MOD;
            ans *= rp.back();
        } else if (f2) {
            ans *= modpow(kp.back(), MOD-2);
            ans %= MOD;
            ans *= rm.back();
        }
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;

    cout << ans << endl;
}