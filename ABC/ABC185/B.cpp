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
    int n, m, t;
    cin >> n >> m >> t;

    int pre = 0;
    bool ans = true;
    int e = n;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        e -= (a - pre);
        e = max(0, e);
        if (e <= 0) ans = false;
        e += (b - a);
        e = min(e, n);
        pre = b;
    }
    e -= t - pre;
    if (e <= 0) ans = false;

    cout << (ans? "Yes" : "No") << endl;
}