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
    int a[3][3];
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            cin >> a[i][j];
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int b;
        cin >> b;
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (b == a[j][k]) a[j][k] = -1;
            }
        }
    }

    bool ans = false;
    for (int i=0; i<3; i++) {
        bool f = true;
        for (int j=0; j<3; j++) {
            if (a[i][j] >= 0) f = false;
        }
        if (f) ans = true;
    }

    for (int i=0; i<3; i++) {
        bool f = true;
        for (int j=0; j<3; j++) {
            if (a[j][i] >= 0) f = false;
        }
        if (f) ans = true;
    }

    if (a[0][0]<0 && a[1][1]<0 && a[2][2]<0) ans = true;
    if (a[0][2]<0 && a[1][1]<0 && a[2][0]<0) ans = true;


    cout << (ans? "Yes" : "No") << endl;
}