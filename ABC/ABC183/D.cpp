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
    int n, w;
    cin >> n >> w;

    vector sum(200'010, 0LL);
    for (int i=0; i<n; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        sum[s] += p;
        sum[t] -= p;
    }

    bool ans = true;
    for (int i=0; i<200'001; i++) {
        sum[i+1] += sum[i];
        if (sum[i] > w) ans = false;
    }

//    for (int i=0; i<=10; i++) cerr<<sum[i]<<" ";cerr<<endl;

    cout << (ans? "Yes" : "No") << endl;

}