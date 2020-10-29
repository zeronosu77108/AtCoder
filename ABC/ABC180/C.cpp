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

int main() {
    int64 n;
    cin >> n;

    vector<int64> ans;
    for (int64 i=1; i*i<=n; i++) {
        if (n%i) continue;
        ans.emplace_back(i);
        if (n/i != i) ans.emplace_back(n/i);
    }
    sort(ans.begin(), ans.end());

    for (auto a : ans) cout << a << endl;
}