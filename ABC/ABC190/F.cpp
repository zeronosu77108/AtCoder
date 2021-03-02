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

class BIT {
    int n;
    vector<long> d;
public:
    BIT(int _n=0) {n=_n; d=vector<long>(n+1);}
    void add(int i, long x=1) { for (i++; i <= n; i += i&-i) d[i] += x; }
    long sum(int i) { long x = 0; for (i++; i; i -= i&-i) x += d[i]; return x; }
};

int main() {
    int n;
    cin >> n;

    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    BIT bit(n);
    long sum = 0;
    for (int i=0; i<n; i++) {
        sum += i - bit.sum(a[i]);
        bit.add(a[i]);
    }

    cout << sum << endl;
    for (int i=0; i<n-1; i++) {
        sum += n - 1 - 2*a[i];
        cout << sum << endl;
    }
}