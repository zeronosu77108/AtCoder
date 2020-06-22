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
    vector a(n,0LL);
    for (int i=0; i<n; i++) cin >> a[i];
    int64 sum = accumulate(a.begin(), a.end(), 0LL);
    map<int64,int64> mp;
    for (auto ai : a) mp[ai]++;

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int b,c;
        cin >> b >> c;
        sum -= mp[b] * b;
        sum += mp[b] * c;
        mp[c] += mp[b];
        mp[b] = 0;
        cout << sum << endl;
    }
}