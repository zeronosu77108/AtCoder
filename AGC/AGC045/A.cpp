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



pair<bool, int64> basis(int64 x, const vector<int64>& v) {
    for (const auto& vi : v) x = min(x, x^vi);
    return {(x!=0LL), x};
}

/*
 * 後ろから考えて、 1 の人が x!=0 にできるなら勝ち
 * 1 の人のやつが被る可能性 → その bit を立てて勝てるならその前で勝ててるので OK
 * 0 の人が消せる奴を管理しておく。
 *
 * → 0 も 1 も xor の基底を追加していって、 1 の人が従属していないやつがあれば勝ち…？
 */
void solve() {
    int n;
    string s;
    cin >> n;
    vector a(n,0LL);
    for (int i=0; i<n; i++) cin >> a[i];
    cin >> s;

    bool ans = false;
    vector<int64> v;
    for (int i=n-1; i>=0; i--) {
        const auto [f, x] = basis(a[i], v);
        if (f) {
            if (s[i] == '1') ans = true;
            v.emplace_back(x);
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
}