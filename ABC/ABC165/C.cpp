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
using TP = tuple<int,int,int,int>;

void dfs(vector<int> v, const int& pre, const int& n, const int& m, const vector<TP>& abcd, int& ans) {
    if (v.size() >= n) {
        int cnt = 0;
        for (auto [a,b,c,d] : abcd) {
            if (v[b-1] - v[a-1] == c) cnt+=d;
        }
        ans = max(ans, cnt);
        return;
    }

    for (int i=pre; i<=m; i++) {
        v.push_back(i);
        dfs(v,i,n,m, abcd,ans);
        v.pop_back();
    }
}

int main() {
    int n,m,q;
    cin >> n >> m >> q;

    vector<TP> abcd;
    for (int i=0; i<q; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        abcd.emplace_back(a,b,c,d);
    }

    sort(abcd.begin(), abcd.end());

    vector v = {1};
    int ans = 0;
    dfs(v,1,n,m, abcd, ans);

    cout << ans << endl;
}