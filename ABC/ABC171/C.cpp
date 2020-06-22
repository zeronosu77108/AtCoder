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

string c(int64 n) {
    if (n==1) return "a";
    string ans;
    while(n!=0) {
        n--;
        ans += 'a' + (n%26);
        n /= 26;
//        if (n==1) break;
    }
    return ans;
}

int main() {
    int64 n;
    cin >> n;
    string ans = c(n);

//    for (int i=1; i<=703; i++) {
//        string t = c(i);
//        reverse(t.begin(), t.end());
//        cout << i << " : " << t << endl;
//    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}