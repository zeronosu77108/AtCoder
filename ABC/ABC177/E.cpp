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
#include <unordered_map>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;
using P = pair<int64, int64>;

struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
        f[0] = f[1] = -1;
        for (int64 i = 2; i <= n; ++i) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (int64 j = i*i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x) { return f[x] == x;}
    set<int> factorList(int x) {
        set<int> res;
        while (x != 1) {
            res.insert(f[x]);
            x /= f[x];
        }
        return res;
    }
//    vector<P> factor(int x) {
//        vector<int> fl = factorList(x);
//        if (fl.size() == 0) return {};
//        vector<P> res(1, P(fl[0], 0));
//        for (int p : fl) {
//            if (res.back().first == p) {
//                res.back().second++;
//            } else {
//                res.emplace_back(p, 1);
//            }
//        }
//        return res;
//    }
    vector<pair<int64,int>> factor(int64 x) {
        vector<pair<int64,int>> res;
        for (int p : primes) {
            int y = 0;
            while (x%p == 0) x /= p, ++y;
            if (y != 0) res.emplace_back(p,y);
        }
        if (x != 1) res.emplace_back(x,1);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector a(n,0);
    for (int i=0; i<n; i++) cin >> a[i];

    Sieve si(1000001);
    unordered_map<int, bool> um;
    bool f = true;
    for (int i=0; i<n; i++) {
        set<int> s = si.factorList(a[i]);
        for (auto ss : s) {
            if (um[ss]) {
                f = false;
                break;
            }
            um[ss] = true;
        }
        if (!f) break;
    }
    if (f) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int GCD = a[0];
    for (int i=1; i<n; i++) GCD = gcd(GCD, a[i]);
    if (GCD == 1) {
        cout << "setwise coprime" << endl;
        return 0;
    }

    cout << "not coprime" << endl;
}