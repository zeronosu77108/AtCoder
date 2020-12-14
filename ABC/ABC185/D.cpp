//
// Created by zeronosu77108 on Dec 13, 2020.
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
    int n, m;
    cin >> n >> m;
    if (m==0) {
        cout << 1 << endl;
        return 0;
    }
    vector a(m, 0L);
    for (int i=0; i<m; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long k = INT_MAX;
    if (a.front() != 1 && a.front()-1 != 0) k = min(k, a.front() - 1);

    for (int i=1; i<a.size()-1; i++) {
        if (a[i+1] - a[i] - 1 == 0) continue;
        k = min(k, a[i+1] - a[i] - 1);
    }

    if (a.back() != n && n-a.back()-1 != 0) k = min(k, n - a.back() - 1);

    a.emplace_back(0);
    a.emplace_back(n+1);
    sort(a.begin(), a.end());


    if (n == m) {
        cout << 0 << endl;
        return 0;
    }

    long ans = 0;
    for (int i=0; i<a.size()-1; i++) {
        long d = abs(a[i+1] - a[i] - 1);
        ans += (d + k - 1) / k;
    }

    cout << ans << endl;
}