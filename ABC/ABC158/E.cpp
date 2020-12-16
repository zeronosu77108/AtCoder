//
// Created by zeronosu77108 on Dec 16, 2020.
//
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
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

int main() {
    int n, p;
    string s;
    cin >> n >> p >> s;

    reverse(s.begin(), s.end());
    vector dp(n+1, 0L);
    if (p==2 || p==5) {
        for (int i=0; i<n; i++) {
            dp[i+1] = dp[i] + ((s[i]-'0')%p? 0 : (n-i));
        }
        cout << dp.back() << endl;
        return 0;
    }

    unordered_map<long, long> mp;
    mp[0] = 1;
    // (sum_j - sum_i) / 10^i ≡ 0 (mod p)
    // sum_j - sum_i ≡ 0 (mod p)
    // sum_j ≡ sum_i (mod p)
    int sum = 0;
    int d = 1;
    for (int i=0; i<n; i++) {
        sum += (s[i] - '0') * d;
        sum%=p;
        d*=10; d%=p;
        dp[i+1] = dp[i] + mp[sum]++;
    }
    cout << dp.back() << endl;
}