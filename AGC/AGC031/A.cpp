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

const int MOD = 1000000007;
int main() {
    int n;
    string s;
    cin >> n >> s;

    int64 ans = 1;
    map<char, int64> mp;
    for (auto c : s) mp[c]++;

    for (char c='a'; c<='z'; c++) {
        ans *= mp[c] + 1;
        ans %= MOD;
    }
    ans--;
    if (ans<0) ans+=MOD;

    cout << ans << endl;
}