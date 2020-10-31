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

const int MOD = 998244353;
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
} comb(100005);

class UnionFind {
private:
    vector<long long> par,_size;
public:
    UnionFind(long long n) : par(n+1),_size(n+1,1) {
        iota(par.begin(), par.end(), 0);
    }

    long long root(long long x) {
        if (x == par[x]) return x;
        else return par[x] = root(par[x]);
    }

    bool is_same(long long x, long long y) {
        return root(x) == root(y);
    }

    bool merge(long long x, long long y) {
        x = root(x); y = root(y);
        if (is_same(x,y)) return false;
        if (_size[x] < _size[y]) swap(x,y);
        par[y] = x;
        _size[x] += _size[y];
        return true;
    }

    long long size(long long x) {
        return _size[root(x)];
    }
};



int main() {
    int n, k;
    cin >> n >> k;
    vector a(n, vector(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    mint r = 1;
    UnionFind runi(n);
    for (int i=0; i<n; i++) {
        bool f1 = false;
        for (int j=0; j<n; j++) {
            if (i==j) continue;
            bool f2 = true;
            for (int l=0; l<n; l++) {
                if (a[l][i] + a[l][j] > k) f2 = false;
            }
            if (f2) {
                f1 = true;
                runi.merge(i, j);
            }
        }
    }

    vector rused(n, false);
    for (int i=0; i<n; i++) {
        int p = runi.root(i);
        if (rused[p]) continue;
        rused[p] = true;
        r *= comb.fact[runi.size(p)];
    }

    mint c = 1;
    UnionFind cuni(n);
    for (int i=0; i<n; i++) {
        bool f1 = false;
        for (int j=0; j<n; j++) {
            if (i==j) continue;
            bool f2 = true;
            for (int l=0; l<n; l++) {
                if (a[i][l] + a[j][l] > k) f2 = false;
            }
            if (f2) {
                f1 = true;
                cuni.merge(i, j);
            }
        }
    }

    vector cused(n, false);
    for (int i=0; i<n; i++) {
        int p = cuni.root(i);
        if (cused[p]) continue;
        cused[p] = true;
        c *= comb.fact[cuni.size(p)];
    }

//    debug(r);
//    debug(c);

    cout << r * c << endl;
}
