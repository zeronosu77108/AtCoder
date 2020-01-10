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
    int n,m;
    cin >> n >> m;
    vector<map<char,int>> colors(n);
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            colors[i][s[j]]++;
        }
    }


    int ans = INT_MAX;
    for (int i=1; i<n; i++) {
        int cnt = 0;
        for (int l=0; l<i; l++) cnt += colors[l]['B'] + colors[l]['R'];
        int cnt_tmp = cnt;
        for (int j=1; j<n; j++) {
            cnt = cnt_tmp;
            if (i+j >= n) continue;
            int k = n - i - j;

            for (int l=i; l<i+j; l++) cnt += colors[l]['W'] + colors[l]['R'];

            for (int l=i+j; l<i+j+k; l++) cnt += colors[l]['W'] + colors[l]['B'];
            ans = min(ans, cnt);
        }

    }

    cout << ans << endl;
}