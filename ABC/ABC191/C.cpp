//
// Created by zeronosu77108 on Feb 11, 2021.
//
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
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];

    vector dx = { -1,  0, -1,  0};
    vector dy = { -1, -1,  0,  0};
    int ans = 0;

    for (int i=1; i<h; i++) {
        for (int j=1; j<w; j++) {
            int cnt = 0;
            for (int k=0; k<4; k++) {
                if (s[i+dy[k]][j+dx[k]] == '#') cnt++;
            }
            if (cnt == 1 || cnt == 3) ans++;
        }
    }

    cout << ans << endl;
}