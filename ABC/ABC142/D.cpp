#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

typedef long long ll;

map<ll, ll> prime_factorization(ll n) {
  map<ll,ll> res;
  ll tmp = n;
  for (ll i=2; i*i<=n; i++) {
    while(tmp!=0 && tmp%i == 0) {
      res[i]++;
      tmp /= i;
    }
  }
  if (tmp!=1) res[tmp]++;
  return res;
}

ll gcd(ll a, ll b) {
  if ( a%b==0 ) return b;
  return gcd(b, a%b);
}

int main() {
  ll a,b;
  ll ans = 1;
  cin >> a >> b;
  ll GCD = gcd(a,b);

  map<ll,ll> pf = prime_factorization(GCD);
  for (auto p : pf) {
    if (p.second > 0) ans++;
  }

  cout << ans << endl;
}