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
using TP = tuple<int, int, int>;

long double f(const int a, const int b, const int c, vector<vector<vector<long double>>>& dp) {
    if (dp[a][b][c] > 0) return dp[a][b][c];
    if (a==100 || b==100 || c==100) return 0;
    dp[a][b][c] += (f(a+1, b, c, dp)+1) * a / (a+b+c);
    dp[a][b][c] += (f(a, b+1, c, dp)+1) * b / (a+b+c);
    dp[a][b][c] += (f(a, b, c+1, dp)+1) * c / (a+b+c);
    return dp[a][b][c];
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector dp(101, vector(101, vector(101, 0.0L)));
    cout << f(a, b, c, dp) << endl;
}