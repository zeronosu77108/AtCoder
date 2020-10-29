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
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;

    vector sdp(n, false);
    vector fdp(n, false);

    sdp[a-1] = true;
    fdp[b-1] = true;

    for (int i=0; i<n; i++) {
        if (i+1<n && s[i+1] != '#') fdp[i+1] = fdp[i+1] || fdp[i];
        if (i+2<n && s[i+2] != '#') fdp[i+2] = fdp[i+2] || fdp[i];
    }

    bool f = false;
    {
        int cnt = 0;
        for (int i=b-1; i<min(d+1, n); i++) {
            if (s[i-1] == '.' && s[i] == '.') cnt++;
            else cnt = 0;
            if (cnt >= 2) f = true;
        }
    }
    if (!f) s[d-1] = '#';

    for (int i=0; i<n; i++) {
        if (i+1<n && s[i+1] != '#') sdp[i+1] = sdp[i+1] || sdp[i];
        if (i+2<n && s[i+2] != '#') sdp[i+2] = sdp[i+2] || sdp[i];
    }

//    debug(sdp);
//    debug(fdp);

    if (sdp[c-1] && fdp[d-1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}