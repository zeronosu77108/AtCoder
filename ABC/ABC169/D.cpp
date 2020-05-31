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


void facts(int64 n, map<int64,int64>& fact) {
    int64 t = n;
    for (int64 i=2; i*i<=t; i++) {
        while(n%i == 0) {
            fact[i]++;
            n /= i;
        }
    }
    if (n != 1) fact[n]++;
}

int main() {
    int64 n;
    cin >> n;

    map<int64,int64> fact;
    facts(n,fact);

    int64 ans = 0;
    for (auto [a,b] : fact) {

        for (int i=1; i<=b; i++) {
            b-=i;
            ans++;
        }
    }
    cout << ans << endl;
}

