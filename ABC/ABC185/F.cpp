//
// Created by zeronosu77108 on Dec 13, 2020.
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
    SegTree(const long long n, const T e = 0L, const OP op = plus{}) : seg(n*2+1, e), n(n), e(e) , op(op) {}
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
    int n, q;
    cin >> n >> q;;
    SegTree seg(n+1, 0L, bit_xor{});
    vector a(n, 0L);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        seg.set(i+1, a[i]);
    }

    for (int i=0; i<q; i++) {
        long t, x, y;
        cin >> t >> x >> y;
        if (t == 1) seg.update(x, y);
        else cout << seg.query(x, y+1) << endl;
    }
}