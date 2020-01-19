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
#define debug(v) {cout<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}


typedef long long int64;
typedef pair<int64,int64> P;

int64 msd(int64 n) {
    while(n/10){
        n /= 10;
    }
    return n;
}

int main() {
    int n;
    cin >> n;
    map<P,int> mp;

    for (int i=1; i<=n; i++) {
        mp[P(msd(i), i % 10)]++;
    }

    int64 ans = 0;
    for (int i=1; i<=n; i++) {
        ans += mp[P(i%10,msd(i))];
    }

    cout << ans << endl;
}