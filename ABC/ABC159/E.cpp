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
using P = pair<int64,int64>;

vector<vector<int>> grouping(const int& sep, const int& w, const vector<string>& s) {
    int h = __builtin_popcount(sep) + 1;
    vector<vector<int>> res(h, vector<int>(w,0));
    for (int i=0; i<w; i++) {
        int g = 0;
        for (int j=0; j<s.size(); j++) {
            res[g][i] += (s[j][i] == '1');
            if (sep>>j & 1) g++;
        }
    }
    return res;
}

int main() {
    int64 h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (int64 i=0; i<h; i++) cin >> s[i];

    int64 ans = LONG_MAX;

    for (int64 i=0; i<(1<<(h-1)); i++) {
        int group = __builtin_popcount(i) + 1;

        // グループ毎に縦向きに計算しておく
        vector<vector<int>> gsum = grouping(i, w, s);

        int64 cnt = group - 1;
        vector<int> count(group);
        for (int j=0; j<w; j++) {
            for (int g=0; g<group; g++) {
                // 1列足して k より大きくなるならそもそもこの横分割はダメ
                if (gsum[g][j] > k) {
                    cnt = INT_MAX;
                    goto LOOP_EXIT;
                }

                // 1列足して k より大きくなるなら，ここで分割（和をリセット）
                if (count[g] + gsum[g][j] > k) {
                    cnt++;
                    for (int g=0; g<group; g++) count[g] = 0;
                    break;
                }
            }

            // グループ毎に計算しておく
            for (int g=0; g<group; g++) count[g] += gsum[g][j];
        }

        LOOP_EXIT:
        ans = min(ans, cnt);
    }

    cout << ans << endl;
}