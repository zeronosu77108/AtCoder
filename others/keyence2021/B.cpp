//
// Created by zeronosu77108 on Jan 16, 2021.
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

using int64 = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    vector cnt(n+1, 0);
    for (int i=0; i<n; i++) cnt[a[i]]++;

    long ans = 0;
    long t = k;
    for (long i=0; i<n && t>0; i++) {
        const long d = max(0L, t - cnt[i]);
        ans += i * d;
        t -= d;
    }
    ans += t * n;


    cout << ans << endl;
}