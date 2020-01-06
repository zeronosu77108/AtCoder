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
    mint(const long long x=0) : x(x%mod) {}

    mint& operator+=(const mint a) {
        if ( (x+=a.x) >= mod) x-=mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ( (x+= mod-a.x) >= mod) x-= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x*=a.x) %= mod;
        return *this;
    }
    mint& operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint& operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint& operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(long long t) const {
        if (!t) return mint(1);
        mint a = pow(t>>1);
        a*=a;
        if(t&1) a*= *this;
        return a;
    }

    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint& operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};


mint frac(int n) {
    mint ans(1);
    for (int i=1; i<=n; i++) ans *= i;
    return ans;
}


int main() {
    int w,h;
    cin >> w >> h;
    w--; h--;


    mint ans = frac(w + h);
    ans /= frac(w);
    ans /= frac(h);
    cout << ans.x << endl;
    return 0;
}