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
    int n,m;
    bool ans = false;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);

    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];

    for (int i=0; i<n-m+1; i++) {
        for(int j=0; j<n-m+1; j++) {

            bool f = true;
            for (int k=0; k<m; k++) {
                for (int l=0; l<m; l++) {
                    if (a[i+k][j+l] != b[k][l]) f = false;
                }
            }

            if (f) ans = true;
        }
    }

    cout << (ans? "Yes" : "No") << endl;
}