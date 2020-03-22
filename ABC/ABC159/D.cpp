#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int main() {
    int64 n;
    cin >> n;
    map<int64,int64> mp;
    vector<int64> a(n);
    for (int64 i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int64 ans = 0;
    vector<map<int64,int64>> tmp(2);
    for (auto p : mp) {
        int64 x,c;
        tie(x,c) = p;
        ans += tmp[0][x] = c*(c-1)/2;
        tmp[1][x] = (c-2)*(c-1)/2;
    }

    for (int64 i=0; i<n; i++) {
        cout << ans - tmp[0][a[i]] + tmp[1][a[i]] << endl;
    }
}