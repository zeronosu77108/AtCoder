//
// Created by zeronosu77108 on Nov 27, 2020.
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
//#include <com/**/plex>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

int main() {
    long n, m;
    cin >> n >> m;
    vector a(n, 0L);
    for (int i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector csum(n+1, 0L);
    for (int i=0; i<n; i++) csum[i+1] += csum[i] + a[i];

    long l = 0;
    long r = LONG_MAX / 9;
    while(l+1 < r) {
        long mid = (l+r) / 2;
        long cnt = 0;
        for (int i=0; i<n; i++) {
            const long res = mid - a[i];
            auto it = lower_bound(a.begin(), a.end(), res);
            cnt += a.end() - it;
        }

        if (m <= cnt) l = mid;
        else r = mid;
    }

    long ans = 0;
    long cnt = 0;
    for (int i=n-1; i>=0; i--) {
        const long res = l - a[i];
        auto it = lower_bound(a.begin(), a.end(), res);
        long c = a.end() - it; cnt += c;
        ans += a[i]*c + csum[n] - csum[n-c];
    }
    if (cnt > m) ans -= l * (cnt-m);

    cout << ans << endl;
}