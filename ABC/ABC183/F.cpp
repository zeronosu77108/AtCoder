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
    vector<long long> par;
public:
    vector<map<int,long>> s;
    explicit UnionFind(long long n) : par(n+1),s(n+1) {
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
        if (s[x].size() < s[y].size()) swap(x,y);
        par[y] = x;
        for (auto [k, v] : s[y]) s[x][k] += v;
        return true;
    }

};


int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uni(n);

    for (int i=1; i<=n; i++) {
        int c;
        cin >> c;
        uni.s[i][c]++;
    }



    for (int i=0; i<q; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t==1) {
            uni.merge(a, b);
            continue;
        }

        a = uni.root(a);
        cout << uni.s[a][b] << endl;
    }
}
