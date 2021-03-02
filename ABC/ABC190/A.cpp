//
// Created by zeronosu77108 on Jan 30, 2021.
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
    int a, b, c;
    cin >> a >> b >> c;

    if (c) {
        if (a >= b) {
            cout << "Takahashi" << endl;
        } else {
            cout << "Aoki" << endl;
        }
    } else {
        if (a <= b) {
            cout << "Aoki" << endl;
        } else {
            cout << "Takahashi" << endl;
        }
    }
}