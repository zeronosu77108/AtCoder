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

int64 calc(const vector<int64>& a, const vector<int64>& s) {
    int64 res = 0;
    int64 pre = 0;
    int n = a.size();
    auto si = s.begin();
    for (int i=0; i<n; i++) {
        int ad = 0;
        if (i == *si) {
            ad = max(0LL, pre - a[i] + 1);
            res += ad;
            if (++si == s.end()) break;
        }
        pre = max(pre, a[i] + ad);
    }
    return res;
}

int64 dfs(const int& i, const int& k, const vector<int64>&a, vector<int64> s) {
    if (s.size() == k) return calc(a,s);
    if (i >= a.size()) return LONG_MAX;
    int64 res = LONG_MAX;

    res = min(res, dfs(i+1, k, a, s));
    s.push_back(i);
    res = min(res, dfs(i+1, k, a, s));
    return res;
}


int main() {
    int n,k;
    cin >> n >> k;
    vector<int64> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int64> s;
    int64 ans = dfs(0, k, a, s);

    cout << ans << endl;
}
