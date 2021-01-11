//
// Created by zeronosu77108 on Jan 10, 2021.
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
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<P> a;
    for (int i=0; i<1<<n; i++) {
        int ai;
        cin >> ai;
        a.emplace_back(ai, i);
    }


    while(a.size() > 2) {
        vector<P> next;
        for (int i=0; i<a.size(); i+=2) {
            next.emplace_back(max(a[i], a[i+1]));
        }
        swap(a, next);

    }

    cout << min(a[0], a[1]).second + 1 << endl;
}