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
    string s,t;
    cin >> t >> s;
    int n = t.size();
    int ans = INT_MAX;
    for (int i=0; i<n; i++) {
        int cnt = 0;
        if (i+s.size() > n) break;
        for (int j=0; j<s.size(); j++) {
            if (t[i+j] != s[j]) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}