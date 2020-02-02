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
using P = pair<int,int>;

struct unionfind {
    vector<long long> par;
    vector<long long> _size;

    // コンストラクタ
    explicit unionfind(long n) : par(n), _size(n,1) {
        for(long long i=0; i<n; i++) par[i]=i;
    }

    void init(long long n) {
        par = vector<long long>(n);
        _size = vector<long long>(n,1);
        for(long long i=0; i<n; i++) par[i]=i;
    }

    long long root(long long x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }

    bool merge(long long x, long long y) {
        x = root(x);
        y = root(y);
        if (x==y) return false;

        if(_size[x]<_size[y]) swap(x,y);

        _size[x] += _size[y];
        par[y] = x;
        return true;
    }

    bool issame(long long x, long long y) {
        return root(x) == root(y);
    }

    long long size(long long x) {
        return _size[root(x)];
    }
};

int main() {
    int n,k,l;
    cin >> n >> k >> l;
    unionfind load(n+1);
    unionfind train(n+1);
    load.init(n+1);
    train.init(n+1);

    for (int i=0; i<k; i++) {
        int64 p,q;
        cin >> p >> q;
        load.merge(p,q);
    }

    for (int i=0; i<l; i++) {
        int r,s;
        cin >> r >> s;
        train.merge(r,s);
    }

    map<P, int> ans;
    for (int i=1; i<=n; i++) ans[P(load.root(i), train.root(i))]++;

    for (int i=1; i<=n; i++) {
        P key = P(load.root(i), train.root(i));
        cout << ans[key] << (i==n? "\n" : " ");
    }
}