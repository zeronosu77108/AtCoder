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
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int64, int64>> wv;
    for (int i=0; i<n; i++) {
        int64 w, v;
        cin >> w >> v;
        wv.emplace_back(w, v);
    }

    const auto cmp = [](pair<int64, int64>& x, pair<int64, int64>& y) { if (x.second==y.second) return x.first>y.first; else return x.second<y.second; };
    sort(wv.begin(), wv.end(), cmp);

    vector x(m, 0LL);
    for (int i=0; i<m; i++) cin >> x[i];

    for (int _=0; _<q; _++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        vector v = wv;
        int64 ans = 0;

        vector used(m, false);
        while (!v.empty()) {
            int index = -1;
            int xmin = INT_MAX;

            const auto [wi, vi] = v.back(); v.pop_back();
            for (int i=0; i<m; i++) {
                if (l<=i && i<=r) continue;
                if (used[i]) continue;

                if (wi <= x[i] && x[i] < xmin) {
                    index = i;
                    xmin = x[i];
                }
            }

            if (index>=0) {
                used[index] = true;
                ans += vi;
            }
        }

        cout << ans << endl;
    }
}