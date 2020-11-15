#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector t(n, vector(n, 0));
    vector v(n-1, 0);
    iota(v.begin(), v.end(), 1);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> t[i][j];
        }
    }
    int ans = 0;
    do {
        int64 d = t[0][v[0]] + t[v.back()][0];
        for (int i=0; i<n-2; i++) {
            d += t[v[i]][v[i+1]];
        }
        if (d == k) ans++;
    } while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}