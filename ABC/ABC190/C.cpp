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
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;

    vector<P> ab;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ab.emplace_back(a, b);
    }

    int k;
    cin >> k;
    vector<P> cd;
    for (int i=0; i<k; i++) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        cd.emplace_back(c, d);
    }

    int ans = 0;
    for (int i=0; i<1<<k; i++) {
        vector di(n, 0);

        for (int j=0; j<k; j++) {
            const auto& [c, d] = cd[j];
            if (i>>j&1) di[c]++;
            else di[d]++;
        }

        int cnt = 0;
        for (int i=0; i<m; i++) {
            const auto& [a, b] = ab[i];
            if (di[a] && di[b]) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}