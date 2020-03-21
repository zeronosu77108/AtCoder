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
template <typename T> bool chmin(T& a, const T& b) {if(a>b){a=b; return true;} return false;}

using int64 = long long;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];

    vector<vector<int64>> dp(h, vector<int64>(w, INT_MAX));
    dp[0][0] = (s[0][0] == '#');

    const vector<int> dx = {+1, 0};
    const vector<int> dy = { 0,+1};

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {

            if (i+1 < h) {
                int64 d = dp[i][j];
                if (s[i][j] == '.' && s[i+1][j] == '#') d++;

                chmin(dp[i + 1][j], d);
            }

            if (j+1 < w) {
                int64 d = dp[i][j];
                if (s[i][j] == '.' && s[i][j+1] == '#') d++;
                chmin(dp[i][j + 1], d);
            }
        }
    }

    cout << dp[h-1][w-1] << endl;
}