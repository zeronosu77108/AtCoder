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
    int h,w,n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<int> colors;

    for (int i=0; i<n; i++) {
        for (int j=0; j<a[i]; j++) colors.push_back(i+1);
    }

    vector<vector<int>> ans(h, vector<int> (w, -1));

    for (int i=0; i<h; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; j++) {
                ans[i][j] = colors.back();
                colors.pop_back();
            }
        } else {
            for (int j = w - 1; j >= 0; j--) {
                ans[i][j] = colors.back();
                colors.pop_back();
            }
        }
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
}