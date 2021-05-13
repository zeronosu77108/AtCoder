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

int main() {
    int a, b, w;
    cin >> a >> b >> w;
    w *= 1000;

    int amin = INT_MAX;
    int amax = INT_MIN;

    for (int i=1; i<2000000; i++) {
        if (i*a <= w && w <= i*b) {
            amin = min(amin, i);
            amax = max(amax, i);
        }
    }

    if (amin==INT_MAX || amax==INT_MIN) {
        cout << "UNSATISFIABLE" << endl;
    } else {
        cout << amin << " " << amax << endl;
    }
}