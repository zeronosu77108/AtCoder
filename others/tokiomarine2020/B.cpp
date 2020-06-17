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
    int64 a,b,v,w,t;
    cin >> a >> v >> b >> w >> t;

    if (v-w > 0 && (v-w)*t >= abs(a-b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

/*
 * a-b  == iw - iv
 * a-b == i(w-v)
 */