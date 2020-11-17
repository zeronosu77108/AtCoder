#include <iostream>
#include <string>
#include <vector>

using namespace std;


const int MOD = 1'000'000'007;
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

int main() {
    string l;
    cin >> l;

    int n = l.size();

    vector dp(2, vector(n+1, mint(0)));
    dp[1][0] = 1;

    for (int i=0; i<n; i++) {
        if (l[i] == '1') {
            dp[1][i+1] = dp[1][i] * 2;
            dp[0][i+1] = dp[1][i] + dp[0][i] * 3;
        } else {
            dp[1][i+1] = dp[1][i];
            dp[0][i+1] = dp[0][i] * 3;
        }
    }

    cout << dp[0][n] + dp[1][n] << endl;
}