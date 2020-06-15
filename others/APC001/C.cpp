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
    int n;
    cin >> n;

    vector<char> t(n, '-');
    cout << 0 << endl;
    string s;
    cin >> s;
    if (s == "Vacant") return 0;
    t[0] = s[0];
    cout << n-1 << endl;
    cin >> s;
    if (s == "Vacant") return 0;
    t[n-1] = s[0];

    int l = 0;
    int r = n-1;

    int cnt = 2;
    while(true) {
        cnt++;
        int m = (l+r)/2;
        debug(m);
        cout << m << endl;
        cin >> s;
        if (s == "Vacant") return 0;
        t[m] = s[0];
        if ((t[l] == t[m] && l%2==m%2) || (t[l] != t[m] && l%2!=m%2)) {
            l = m;
        } else {
            r = m;
        }
        if (cnt>=20) return 1;
    }

}