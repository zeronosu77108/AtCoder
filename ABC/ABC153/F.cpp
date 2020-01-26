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

int N, Q;
struct LazySegmentTree {
private:
    int n;
    vector<int64> node, lazy;

public:
    LazySegmentTree(vector<int64> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, int64 x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    int64 getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        int64 vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int64 vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};


int main() {
    int64 n,d,a;
    int64 ans = 0;
    cin >> n >> d >> a;
    vector<pair<int64,int64>> xh;
    vector<int64> x(n);
    vector<int64> h(n+1,0);

    for (int64 i=0; i<n; i++) {
        cin >> x[i] >> h[i];
        xh.emplace_back(x[i], h[i]);
    }

    sort(xh.begin(), xh.end());

    for (int i=0; i<n; i++) {
        x[i] = xh[i].first;
        h[i] = xh[i].second;
    }
    LazySegmentTree seg(h);




    for (int64 i=0; i<n; i++) {
//        for (int64 j=0; j<n; j++) cout << seg.getsum(j,j+1) << " "; cout<<endl;

        h[i] = seg.getsum(i,i+1);
        if (h[i] <= 0) continue;
        int64 r = x[i] + 2*d;

        auto it = upper_bound(x.begin(), x.end(), r);
        it--;
        int64 index = it - x.begin();

        int64 nboms = (h[i] + a - 1) / a;
        ans += nboms;
        seg.add(i,index+1, -(nboms * a));
    }

    cout << ans << endl;
}