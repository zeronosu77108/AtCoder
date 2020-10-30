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
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    vector s(h, string(w, '1'));

    for (int j=0; j<b; j++) {
        for (int i=a; i<w; i++) {
            s[j][i] = '0';
        }
    }

    for (int i=0; i<a; i++) {
        for (int j=b; j<h; j++) {
            s[j][i] = '0';
        }
    }

    for (int i=0; i<h; i++) {
        cout << s[i] << endl;
    }
}