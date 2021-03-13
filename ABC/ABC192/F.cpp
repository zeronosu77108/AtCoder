//
// Created by zeronosu77108 on Mar 13, 2021.
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
template <class T>ostream &operator<<(ostream &o,const optional<T>&v){o<<(v? to_string(v.value()) : "-");return o;}
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

template <class T> bool chmin(optional<T>& a, T b) { if(!a || a.value() > b) { a = b; return true; } return false; }
template <class T> bool chmax(optional<T>& a, T b) { if(!a || a.value() < b) { a = b; return true; } return false; }

int main() {
    int64 n, x;
    cin >> n >> x;

    vector a(n, 0LL);
    for (int i=0; i<n; i++) cin >> a[i];

    // k個使うことを決め打ち､ mod k で分類してできるだけ大きくして x%k と同じになるやつがあれば､それは答えの候補（min取る）
    int64 ans = LONG_MAX;
     for (int k=1; k<=n; k++) {
        vector dp(k+1, vector(k, optional<int64>()));
        dp[0][0] = 0;

        for (int i=0; i<n; i++) {
            vector next(k+1, vector(k, optional<int64>()));
            for (int j=0; j<=k; j++) {
                for (int l=0; l<k; l++) {
                    if (!dp[j][l]) continue;
                    chmax(next[j][l], dp[j][l].value());
                    if (j+1 <= k) chmax(next[j+1][(l+a[i])%k], dp[j][l].value() + a[i]);
                }
            }
            dp = next;
        }

        const auto& d = dp.back()[x % k];
        if (d) ans = min(ans, (x - d.value()) / k);
    }

    cout << ans << endl;
}