//
// Created by zeronosu77108 on Mar 6, 2021.
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
    int n,m;
    cin >> n >> m;

    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    vector mp(n+1, 0);
    for (int i=0; i<m; i++) mp[a[i]]++;
    set<int> s; for (int i=0; i<=m; i++) if(!mp[i]) s.insert(i);

    int ans = *s.begin();
    for (int i=m; i<n; i++) {
        if (0 == --mp[a[i-m]]) s.insert(a[i-m]);
        if(0 == mp[a[i]]++) s.erase(a[i]);
        ans = min(ans, *s.begin());

    }

    cout << ans << endl;
}