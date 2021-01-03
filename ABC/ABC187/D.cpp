//
// Created by zeronosu77108 on Jan 2, 2021.
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
using P = pair<long,long>;

int main() {
    int n;
    cin >> n;

    vector<P> ab;
    long asum = 0;
    for (int i=0; i<n; i++) {
        long a, b;
        cin >> a >> b;
        ab.emplace_back(a,b);
        asum += a;
    }

    sort(ab.rbegin(), ab.rend(), [](const P& x, const P& y){ return 2*x.first+x.second < 2*y.first+y.second; });

    long sum = 0;
    int i = 0;
    for (; i<n; i++) {
        if (sum > asum) break;
        const auto& [a, b] = ab[i];

        asum -= a;
        sum += a + b;
    }

    cout << i << endl;
}