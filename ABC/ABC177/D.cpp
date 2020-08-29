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

class UnionFind {
private:
    vector<long long> par,_size;
public:
    UnionFind(long long n) : par(n+1),_size(n+1,1) {
        iota(par.begin(), par.end(), 0);
    }

    long long root(long long x) {
        if (x == par[x]) return x;
        else return par[x] = root(par[x]);
    }

    bool is_same(long long x, long long y) {
        return root(x) == root(y);
    }

    bool merge(long long x, long long y) {
        x = root(x); y = root(y);
        if (is_same(x,y)) return false;
        if (_size[x] < _size[y]) swap(x,y);
        par[y] = x;
        _size[x] += _size[y];
        return true;
    }

    long long size(long long x) {
        return _size[root(x)];
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    vector g(n+1, vector<int>());

    UnionFind uni(n);
    for (int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        uni.merge(a,b);
    }

    int64 ans = 0;
    for (int i=1; i<=n; i++) {
        ans = max(ans, uni.size(i));
    }

    cout << ans << endl;
}