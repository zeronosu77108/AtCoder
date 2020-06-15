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
using P = pair<int64, int64>;

void diviser(int num, int n, vector<bool>& u) {
    for (int i=num; i<=n; i+=num) {
//        if (u[i]) return;
        u[i] = true;
    }
}

int main() {
    int n;
    cin >> n;
    vector a(n,0);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<P> len;
    len.emplace_back(a[0], 0);
    for (int i=0; i<n; i++) {
        if (len.back().first == a[i]) len.back().second++;
        else len.emplace_back(a[i], 1);
    }

    vector<bool> u(a.back()+1, false);
    int64 ans = 0;
    for (auto [ai,c] : len) {
        if (c<=1 && !u[ai]) ans++;
        diviser(ai, a.back(), u);
    }


    cout << ans << endl;
}