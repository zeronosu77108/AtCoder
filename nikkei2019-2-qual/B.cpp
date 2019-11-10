#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const long mod = 998244353;
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
        if (!t) return 1;
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

int main() {
    long n;
    mint ans(1);
    cin >> n;
    vector<long> dl(n);
    map<long,long> dc;


    for (int i=0; i<n; i++) {
        cin >> dl[i];
        dc[dl[i]]++;
    }

    if (dl[0] != 0) ans.x = 0;
    if (dc[0] > 1) ans.x = 0;
    if (n>2 && dc[1]<=0) ans.x = 0;

    for (auto d : dc) {
        if (d.first < 2) continue;
        ans *= mint(dc[d.first-1]).pow(d.second);
    }

    cout << ans.x << endl;
}