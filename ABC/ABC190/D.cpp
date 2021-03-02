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

// 約数列挙
template <class T> vector<T> enumDivisors(const T n, const bool sorted=false) {
    vector<T> res(1,1);

    for (long long i=2; i*i<=n; i++) {
        if (n%i==0) {
            res.push_back(i);
            if (i*i != n) res.push_back(n/i);
        }
    }

    if (n!=1) res.push_back(n);
    if (sorted) sort(res.begin(), res.end());
    return res;
}

int main() {
    long n;
    cin >> n;

    int ans = 0;
    for (long i=1; i*i<=2*n; i++) {
        if ((2*n)%i == 0) {
           if (i%2 != (2*n/i)%2) ans++;
        }
    }
    cout << ans * 2 << endl;
}