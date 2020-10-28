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

    int ans = INT_MAX;
    for (char c='a'; c<='z'; c++) {
        string t = s;
        int cnt = 0;
        while(any_of(t.begin(), t.end(), [&](const char& ti){return ti!=c;})) {
            cnt++;
            int n = t.size();
            for (int i=1; i<=n; i++) {
                if (t[i]==c) t[i-1] = c;
            }
            t.pop_back();
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}