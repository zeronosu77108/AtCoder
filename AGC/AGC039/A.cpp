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
    int64 k;
    cin >> s >> k;
    int n = s.size();

    map<char, int> mp;
    for (const auto& c : s) mp[c]++;
    if (mp.size() == 1) {
        cout << n*k / 2 << endl;
        return 0;
    }

    int pre = 1;
    int back = 1;
    for (int i=0; i+1<n && s[i]==s[i+1]; i++,pre++);
    for (int i=n-1; i-1>=0 && s[i-1]==s[i]; i--,back++);


    int64 cnt = 0;
    for (int i=1; i<n; i++) {
        if (s[i-1] == s[i]) cnt++,s[i]='-';
    }


    int64 ans = cnt * k;

    if (s[0] == s.back()) {
        ans -= pre/2 * (k-1);
        ans -= back/2 * (k-1);
        ans += (pre+back)/2 * (k-1);
    }

    cout << ans << endl;
}