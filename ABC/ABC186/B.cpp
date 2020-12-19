//
// Created by zeronosu77108 on Dec 19, 2020.
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
    int h, w;
    cin >> h >> w;
    vector a(h, vector(w, 0));

    int amin = INT_MAX;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> a[i][j];
            amin = min(amin, a[i][j]);
        }
    }

    int ans = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            ans += a[i][j] - amin;
        }
    }

    cout << ans << endl;

}