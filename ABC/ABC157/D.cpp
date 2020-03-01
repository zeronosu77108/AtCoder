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

struct unionfind {
    vector<long long> par,_size;
    unionfind(long n) : par(n), _size(n,1) {
        for(long long i=0; i<n; i++) par[i]=i;
    }
    void init(long long n) {
        par = vector<long long>(n);
        _size = vector<long long>(n);
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
    bool issame(long long x, long long y) { return root(x) == root(y); }
    long long size(long long x) { return _size[root(x)]; }
};

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    unionfind friends(n+1);

    vector<int> a(m);
    vector<int> b(m);
    vector<int> c(k);
    vector<int> d(k);

    for (int i=0; i<m; i++) cin >> a[i] >> b[i];
    for (int i=0; i<k; i++) cin >> c[i] >> d[i];

    for (int i=0; i<m; i++) friends.merge(a[i],b[i]);

    vector<int> ans(n+1, 0);
    for (int i=1; i<=n; i++) ans[i] = friends.size(i) - 1;

    for (int i=0; i<m; i++) {
        ans[a[i]]--;
        ans[b[i]]--;
    }

    for (int i=0; i<k; i++) {
        if (friends.issame(c[i], d[i])) {
            ans[c[i]]--;
            ans[d[i]]--;
        }
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << (i!=n? ' ' : '\n');
    }
}