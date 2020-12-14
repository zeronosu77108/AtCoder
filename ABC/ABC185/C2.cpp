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

long fact(long n) {
    long res = 1;
    for (long i=1; i<=n; i++) res *= n;
    return res;
}

int main() {
    long l;
    cin >> l;

    vector<long> x;
    vector<long> y;
    for (long i=0; i<11; i++) {
        x.push_back(l - i - 1);
        y.push_back(11 - i);
    }


    for (int i=0; i<11; i++) {
        for (int j=0; j<11; j++) {
            if (x[j] % y[i] == 0) {
                x[j] /= y[i];
                y[i] = 1;
                break;
            }
        }
    }

    long ans = accumulate(x.begin(), x.end(), 1L, multiplies{});
    ans /= accumulate(y.begin(), y.end(), 1L, multiplies{});
    cout << ans << endl;
}