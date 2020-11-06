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

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

void div(int n, unordered_map<int,int>& mp) {
    while(n%2==0) mp[2]++, n/=2;
    for (int i=3; i*i<=n; i++) {
        while(n%i==0) mp[i]++,n/=i;
    }
    if (n!=1) mp[n]++;
}

const int MOD = 1000000007;
class mint {
    using int64 = long long;
private:
    int64 x;
public:
    mint(const int64 x1=0) { x = x1%MOD; };

    mint& operator++(int n) { x+=1; return *this; };
    mint& operator--(int n) { x-=1; return *this; };
    mint& operator=(int64 n) { x=n%MOD; return *this; };
    mint& operator--() {x-=1; return *this; };
    mint& operator+=(const mint a) { if ( (x+=a.x) >= MOD) x-=MOD; return *this; }
    mint& operator-=(const mint a) { if ( (x+= MOD-a.x) >= MOD) x-= MOD; return *this; }
    mint& operator*=(const mint a) { (x*=a.x) %= MOD; return *this; }
    mint& operator/=(const mint a) { return (*this) *= a.inv();}
    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }
    mint inv() const { return pow(MOD-2);}
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

struct combination {
    vector<mint> fact, ifact;

    // コンストラクタ
    combination(int n):fact(n+1),ifact(n+1) {
        fact[0] = mint(1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*mint(i);
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*mint(i);
    }

    mint nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n]*ifact[r]*ifact[n-r];
    }
    mint nPr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n]*ifact[n-r];
    }
} comb(200005);



int main() {
    int64 n, m;
    cin >> n >> m;

    unordered_map<int,int> mp;
    div(m, mp);

    mint ans = 1;
    for (auto [i, c] : mp) {
        ans *= comb.nCr(c+n-1, n-1);
    }

    cout << ans << endl;
}