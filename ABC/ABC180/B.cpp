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
    vector<long double> x(n);
    for (int i=0; i<n; i++) cin >> x[i];

    long double manhattan = 0;
    long double euclid = 0;
    long double chebyshev = 0;

    for (int i=0; i<n; i++) {
        manhattan += abs(x[i]);
        euclid += abs(x[i]) * abs(x[i]);
        chebyshev = max(chebyshev, abs(x[i]));
    }
    euclid = sqrt(euclid);

    cout << manhattan << endl;
    cout << euclid << endl;
    cout << chebyshev << endl;
}