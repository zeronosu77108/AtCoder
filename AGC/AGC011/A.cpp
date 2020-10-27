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
    int n, c, k;
    cin >> n >> c >> k;
    vector t(n, 0);
    for (int i=0; i<n; i++) cin >> t[i];
    sort(t.begin(), t.end());

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans++;
        int s = t[i] + k;
        int cnt = 1;
        while(i+1<n && cnt<c && t[i+1]<=s) i++,cnt++;
    }

    cout << ans << endl;
}