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
    int n,k;
    long double ans = 0;
    cin >> n >> k;
    vector<double> p;
    for (int i=0; i<n; i++) {
        int pi;
        cin >> pi;

        p.push_back((long double)(1 + pi) / 2);
    }


    long double sum = 0;
    for (int i=0; i<k; i++) sum += p[i];
    ans = sum;

    for (int i=k; i<n; i++) {
        sum += p[i];
        sum -= p[i-k];
        ans = max(ans, sum);
    }

    cout << ans << endl;
}
/*
1/10 + 2/10 + 3/10 + …
(1 + 2 + 3 + …) / 10
*/