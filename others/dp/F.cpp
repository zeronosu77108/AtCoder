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
    string s, t;
    cin >> s >> t;
    int sn = s.size();
    int tn = t.size();

    vector dp(sn+1, vector<int>(tn+1, 0));

    for (int i=0; i<sn; i++) {
        for (int j=0; j<tn; j++) {
            dp[i+1][j+1] = max({dp[i][j+1], dp[i+1][j]});
            if (s[i] == t[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
        }
    }

//    cerr<<"    ";
//    for (int i=0; i<tn; i++) cerr<<t[i]<<" ";cerr<<endl;
//    for (int i=0; i<=sn; i++) {
//        cerr<< (i>0? s[i-1] : ' ') <<" ";
//        for (int j=0; j<=tn; j++) {
//            cerr<<dp[i][j]<<" ";
//        }
//        cerr<<endl;
//    }

    string ans;
    {
        int n = dp[sn][tn];
        while(n > ans.size()) {
            if (s[sn - 1] == t[tn - 1]) {
                ans += s[--sn];
                tn--;
            } else if (dp[sn][tn] == dp[sn-1][tn]) sn--;
            else if (dp[sn][tn] == dp[sn][tn-1]) tn--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}