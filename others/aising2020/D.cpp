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

int64 modpow(int64 a, int64 n, int64 mod) {
    int64 res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    string x;
    cin >> n >> x;

    int pop = count(x.begin(), x.end(), '1');
    map<int64, int64> base;
    for (int64 i=0; i<n; i++) {
        base[pop+1] *= 2;
        base[pop-1] *= 2;
        if (x[i] == '1') {
            base[pop+1] += 1;
            base[pop-1] += 1;
        }

        base[pop+1] %= (pop+1);
        if (pop>1) base[pop-1] %= (pop-1);
    }


    reverse(x.begin(), x.end());
    vector<int64> ans;
    for (int64 i=0; i<n; i++) {
        int64 cp;
        int64 sum;

        if (x[i] == '1' && pop == 1) {
            ans.push_back(0);
            continue;
        }

        if (x[i] == '0') {
            cp = pop + 1;
            sum = base[pop+1];
            sum += modpow(2, i, pop+1);
            sum %= pop+1;
        } else {
            cp = pop - 1;
            sum = base[pop-1];
            sum -= modpow(2, i, pop-1);
            if (sum < 0) sum += pop-1;
            sum %= pop-1;
        }

        int64 t = 1;
        while (sum != 0) {
            sum %= __builtin_popcount(sum);
            t++;
        }
        ans.push_back(t);
    }

    reverse(ans.begin(), ans.end());
    for (auto a : ans) cout<<a<<endl;
}