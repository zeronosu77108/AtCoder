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

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

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
    int n;
    cin >> n;

    vector<pair<double, double>> xy;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        xy.emplace_back(x, y);
    }

    double l = 0;
    double r = 200;
    for (int _=0; _<100; _++) {
        double m = (l+r) / 2;
        UnionFind uni(n+1);

        for (int i=0; i<n; i++) {
            const auto& [x1, y1] = xy[i];
            if (abs(-100 - (y1 - m)) < m) uni.merge(0, i+1);
            if (abs(100 - (y1 + m)) < m) uni.merge(n+1, i+1);

            for (int j=i+1; j<n; j++) {
                const auto& [x2, y2] = xy[j];
                if (hypot(x1-x2, y1-y2) <= 2*m) uni.merge(i+1, j+1);
            }
        }

        if (uni.is_same(0, n+1)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << endl;
}