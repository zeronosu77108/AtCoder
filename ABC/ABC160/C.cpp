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
using P = pair<int,int>;

int main() {
    int k,n;
    cin >> k >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<bool> used(n,false);
    used[0] = true;
    priority_queue<P, vector<P>, greater<>> pq;
    pq.emplace(abs(a[0] + (k - a.back())), n-1);
    pq.emplace(abs(a[0] - a[1]), 1);

    int64 ans = 0;
    while(!pq.empty()) {
        int i,c;
        tie(c,i) = pq.top(); pq.pop();
        if (used[i]) continue;
        used[i] = true;
        ans += c;
        if (i-1 >= 0 && !used[i-1]) pq.emplace(abs(a[i]-a[i-1]), i-1);
        if (i+1 < n && !used[i+1]) pq.emplace(abs(a[i]-a[i+1]), i+1);
    }

    cout << ans << endl;
}