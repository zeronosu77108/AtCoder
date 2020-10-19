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
#include <unordered_map>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;
using P = pair<int, int>;
using TP = tuple<int, int, int>;

class BIT {
    const int n;
    vector<int64> d;
public:
    BIT(int _n=0) : n(_n), d(n+1, 0) {}
    void add(int i, const int64 x=1) { for (i++; i <= n; i += i&-i) d[i] += x; }
    int64 sum(int i) { int64 x = 0; for (i++; i; i -= i&-i) x += d[i]; return x; }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector c(n+1, 0);
    for (int i=1; i<=n; i++) cin >> c[i];

    vector<TP> lr;
    lr.emplace_back(-1, -1, -1);
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        lr.emplace_back(l, r, i);
    }
    sort(lr.begin(), lr.end());

    unordered_map<int, int> pre;
    BIT bit(n+1);
    vector ans(q+1, -1);

    for (int i=n; i>=1; i--) {
        if (pre[c[i]] > 0) bit.add(pre[c[i]], -1);
        bit.add(i, 1);
        pre[c[i]] = i;

        while(get<0>(lr.back()) == i) {
            const auto [l, r, j] = lr.back();
            lr.pop_back();
            ans[j] = bit.sum(r);
        }
    }

    for (int i=1; i<=q; i++) cout << ans[i] << endl;
}