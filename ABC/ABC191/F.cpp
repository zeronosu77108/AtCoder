//
// Created by zeronosu77108 on Feb 11, 2021.
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
#include <unordered_set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    int n;
    cin >> n;

    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    int amin = *min_element(a.begin(), a.end());

    unordered_map<int, int> mp;
    for (const auto& ai : a) {
        for (int i=1; i*i<=ai; i++) {
            if (ai%i == 0) {
                mp[i] = mp[i]? gcd(mp[i], ai) : ai;
                mp[ai/i] = mp[ai/i]? gcd(mp[ai/i], ai) : ai;
            }
        }
    }

    long ans = 0;
    for (const auto& [i, j] : mp) if (i<=amin && i==j) ans++;
    cout << ans << endl;
}