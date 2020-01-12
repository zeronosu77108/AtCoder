#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;

const int mod = 1000000007;
struct mint {
    long long x;
    explicit mint(const long long x=0) : x(x%mod) {}

    mint& operator+=(const mint a) { if ( (x+=a.x) >= mod) x-=mod; return *this; }
    mint& operator-=(const mint a) { if ( (x+= mod-a.x) >= mod) x-= mod; return *this; }
    mint& operator*=(const mint a) { (x*=a.x) %= mod; return *this; }
    mint& operator/=(const mint a) { return (*this) *= a.inv();}
    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    mint operator/(const mint a) const {mint res(*this); return res/=a;}
    mint inv() const { return pow(mod-2);}
    friend ostream& operator<<(ostream &os, const mint a) noexcept { return os << a.x; }
    constexpr bool operator == (const mint& r) const noexcept { return this->x == r.x; }
    constexpr bool operator != (const mint& r) const noexcept { return this->x != r.x; }
    mint pow(long long t) const {
        if (!t) return mint(1);
        mint a = pow(t>>1);
        a*=a;
        if(t&1) a*= *this;
        return a;
    }
};


//mint frac(long long n) {mint res(1); for (int i=1;i<=n;i++)res*=mint(i);return res;}

struct combination {
    vector<mint> fact, ifact;

    // コンストラクタ
    combination(int64 n):fact(n+1),ifact(n+1) {
        fact[0] = mint(1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*mint(i);
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*mint(i);
    }

    mint nCr(int64 n, int64 r) {
        if (r < 0 || r > n) return mint(0);
        return fact[n]*ifact[r]*ifact[n-r];
    }
    mint nPr(int64 n, int64 r) {
        if (r < 0 || r > n) return mint(0);
        return fact[n]*ifact[n-r];
    }
} comb(100010);

int main() {
    int64 n,k;
    cin >> n >> k;
    vector<int64> a(n);
    for (int64 i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    mint ans(0);

//    mint minSum(0);
//    mint maxSum(0);
    for (int64 i=0; i<n; i++) {
        ans += mint(a[i]) * comb.nCr(i,k-1) - mint(a[i]) * comb.nCr(n-i-1,k-1);
//        minSum += mint(a[i]) * comb.nCr(n-i-1, k-1);
//        maxSum += mint(a[i]) * comb.nCr(n, k-1);
    }

//    reverse(a.begin(), a.end());
//    for (int64 i=0; i<n; i++) {
//        maxSum += mint(a[i]) * comb.nCr(n-i-1, k-1);
//    }

//    mint ans = maxSum - minSum;
    cout << ans << endl;
}