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

template <class T, class OP>
class SegTree {
private:
    vector<T> seg;
    const long long n;
    const T e;
    const OP op;
public:
    SegTree(const long long n, const T e, const OP op) : seg(n*2+1, e), n(n), e(e) , op(op) {}
    void update(int i, const T x, bool is_set_only = false) {
        i+=n;
        seg[i] = (is_set_only? x : op(seg[i], x));
        while(i/=2) seg[i] = op(seg[2*i], seg[2*i+1]);
    };

    void set(int i, const T x) {
        i+=n;
        seg[i] = x;
        while(i/=2) seg[i] = op(seg[2*i], seg[2*i+1]);
    };

    T query(int l, int r) {
        l+=n; r+=n;
        T res = e;
        while(l<r) {
            if (l%2) res = op(res, seg[l++]);
            if (r%2) res = op(res, seg[--r]);
            l/=2; r/=2;
        }
        return res;
    }
};

int main() {
    int h, w, m;
    cin >> h >> w >> m;

    vector xy(w, set<long>({h}));
    vector yx(h, set<long>({w}));
    for (int i=0; i<m; i++) {
       int x, y;
       cin >> x >> y;
       x--; y--;
       xy[y].insert(x);
       yx[x].insert(y);
    }

    long ans = 0;
    SegTree seg(w+2, 0L, plus{});

    for (int i=0; i<w; i++) {
        if (*yx.front().begin() < i) { seg.set(i, 1); continue; };
        ans += *xy[i].begin();
    }

     for (int i=0; i<*xy.front().begin(); i++) {
        ans += seg.query(0, *yx[i].begin());
        for (auto y : yx[i]) {
            seg.set(y, 1);
        }
    }

    cout << ans << endl;
}