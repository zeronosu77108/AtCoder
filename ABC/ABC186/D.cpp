//
// Created by zeronosu77108 on Dec 19, 2020.
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
vector<int> trans;

class SegTree {
private:
    vector<long long> cnt;
    vector<long long> seg;
    const long long n, e;
public:
    SegTree(const long long _n, const long long _e) : n(_n), e(_e), seg(_n*2+1, _e), cnt(_n*2+1, _e) {}
    void update(int i, const long x) {
        const auto t = trans[i];
        i+=n;
        cnt[i] += x;
        seg[i] = cnt[i] * t;
        while(i/=2) {
            cnt[i] = cnt[2*i] + cnt[2*i+1];
            seg[i] = seg[2*i] + seg[2*i+1];
        }
    };

    pair<long long, long long> query(int l, int r) {
        l+=n; r+=n;
        pair<long long, long long> res = {e, e};
        while(l<r) {
            if (l%2) res.first+=cnt[l], res.second+=seg[l], l++;
            if (r%2) --r, res.first+=cnt[r], res.second+=seg[r];
            l/=2; r/=2;
        }
        return res;
    }
};


int main() {
    int n;
    cin >> n;

    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];
    SegTree seg(n+1, 0);

    for (int i=0; i<n; i++) trans.push_back(a[i]);
    sort(trans.begin(), trans.end());
    trans.erase(unique(trans.begin(), trans.end()), trans.end());

    for (auto& ai : a) ai = lower_bound(trans.begin(), trans.end(), ai) - trans.begin();

    long ans = 0;
    for (int i=0; i<n; i++) {
        seg.update(a[i], 1);

        auto l = seg.query(0, a[i]);
        auto r = seg.query(a[i]+1, n+1);
        long long lc = abs(l.first*trans[a[i]] - l.second);
        long long rc = abs(r.second - r.first*trans[a[i]]);

        ans += lc + rc;
    }

    cout << ans << endl;
}