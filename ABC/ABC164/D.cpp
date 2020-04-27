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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ss(n+1,0);
    reverse(s.begin(), s.end());

    int d = 1;
    for (int i=0; i<n; i++) {
        ss[i+1] += ss[i] + (s[i]-'0') * d;
        ss[i+1] %= 2019;
        d *= 10; d %= 2019;
    }

    int ans = 0;
    map<int,int> cnt;
    for (int i=0; i<=n; i++) {
        ans += cnt[ss[i]]++;
    }

    cout << ans << endl;
}