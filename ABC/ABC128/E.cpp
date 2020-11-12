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
using P = pair<long, long>;

int main() {
    int n, q;
    cin >> n >> q;

    vector<P> sx;
    vector<P> tx;
    for (int i=0; i<n; i++) {
        int s, t, x;
        cin >> s >> t >> x;
        sx.emplace_back(s - x, x);
        tx.emplace_back(t - x, x);
    }
    sx.emplace_back(LONG_MAX, LONG_MAX);
    tx.emplace_back(LONG_MAX, LONG_MAX);

    sort(sx.rbegin(), sx.rend());
    sort(tx.rbegin(), tx.rend());


    multiset<long> s;
    for (int i=0; i<q; i++) {
        int d;
        cin >> d;

        while (sx.back().first <= d) {
            s.insert(sx.back().second);
            sx.pop_back();
        }

        while (tx.back().first <= d) {
            s.erase(s.find(tx.back().second));
            tx.pop_back();
        }

        if (!s.empty()) {
            cout << *s.begin() << endl;
        } else {
            cout << -1 << endl;
        }
    }
}