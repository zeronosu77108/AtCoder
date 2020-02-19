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

bool ok(const string& s, const int& i) {
    return s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T';
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int r = i;
        while (r < n && ok(s, r)) r++;
        ans = max(ans, r - i);
        i = r;
    }
    cout << ans << endl;
}