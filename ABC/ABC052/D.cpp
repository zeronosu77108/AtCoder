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
    int64 n,a,b;
    cin >> n >> a >> b;
    vector<int> x(n);
    for (int i=0; i<n; i++) cin >> x[i];

    vector<int> diff;
    for (int i=0; i<n-1; i++) diff.push_back(x[i+1] - x[i]);

    auto cal = [&](int64 acc, int64 x){return acc + min(a*x,b);};
    int64 ans = accumulate(diff.begin(), diff.end(), 0LL,  cal);

    cout << ans << endl;
}