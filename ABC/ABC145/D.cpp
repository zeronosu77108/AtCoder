#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const long long mod = 1e9+7;
struct mint {
  long long x;
  mint(const long long x=0) : x(x%mod) {}
  mint& operator+=(const mint a) {if((x+=a.x)>=mod)x-=mod; return *this;}
  mint& operator-=(const mint a) {if((x+=mod-a.x)>=mod)x-=mod; return *this;}
  mint& operator*=(const mint a) {(x*=a.x) %= mod; return *this;}
  mint& operator+(const mint a) const {mint res(*this); return res+=a;}
  mint& operator-(const mint a) const {mint res(*this); return res-=a;}
  mint& operator*(const mint a) const {mint res(*this); return res*=a;}
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t>>1); a*=a;
    if(t&1) a*= *this;
    return a;
  }
  mint inv() const {return pow(mod-2);}
  mint& operator/=(const mint a) {return (*this) *= a.inv();}
  mint& operator/(const mint a) const {mint res(*this); return res/=a;}
};

mint fact(long long n) {
  mint res = 1;
  for (long long i=n; i>0; i--) res*=i;
  return res;
}

int main() {
  long long x,y;
  cin >> x >> y;

  if ((x+y)%3 != 0) {
    puts("0");
    return 0;
  }

  long long a = (2*x-y)/3;
  long long c = (2*y-x)/3;

  if (a<0 || c<0) {
    puts("0");
    return 0;
  }

  mint ans = fact(a+c);
  ans /= fact(a);
  ans /= fact(c);
  cout << ans.x << endl;
  return 0;
}
