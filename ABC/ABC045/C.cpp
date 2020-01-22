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


using int64 = long long;
using P = pair<int64,int64>;


int main() {
    string s;
    cin >> s;
    int64 n = s.size();
    int64 ans = 0;

    for (int i=0; i<(1<<n-1); i++) {
        int64 tmp = 0;
        for (int j=0; j<n; j++) {
            tmp *= 10;
            tmp += s[j] - '0';

            if ((i>>j)&1) {
                ans += tmp;
                tmp = 0;
            }
        }
        ans += tmp;
    }
    cout << ans << endl;
}