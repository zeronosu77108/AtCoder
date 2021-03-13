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
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    string x;
    int64 m;
    cin >> x >> m;
    int n = x.size();

    if (n==1) {
        cout << 1 << endl;
        return 0;
    }

    int64 d = *min_element(x.begin(), x.end()) - '0';

    int64 l = d + 1;
    int64 r = 1'000'000'000'000'000'000;

    while (l+1 < r) {
        int64 mid = (l+r) / 2;
        string t;

        while(y!=0) {
            t += to_string(y % mid);
            y /= mid;
        }

        reverse(t.begin(), t.end());
        cout << mid << " " << t << endl;
        (x<=t? l : r) = mid;
    }

    cout << l << " " << r << " " << d << endl;
    cout << l - d << endl;
}