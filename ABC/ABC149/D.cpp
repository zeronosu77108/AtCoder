#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;



int main() {
    int n,k,r,s,p;
    int64 ans = 0;
    string t;

    cin >> n >> k;
    cin >> r >> s >> p;
    cin >> t;

    map<char, int64> win;
    win['r'] = p;
    win['p'] = s;
    win['s'] = r;


    vector<vector<int64>> dp(n+1, vector<int64> (3, 0));

    for (int i=0; i<n; i++) {
        if (i < k) ans += win[t[i]];
        else if (t[i-k] != t[i]) ans += win[t[i]];
        else t[i] = '-';
    }

    cout << ans << endl;
}