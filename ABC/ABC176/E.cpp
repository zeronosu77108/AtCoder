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

int main() {
    int h,w,m;
    cin >> h >> w >> m;

    set<P> hw;
    map<int,int> hmp;
    map<int,int> wmp;

    int hmax = -1;
    int wmax = -1;
    for (int i=0; i<m; i++) {
        int hi,wi;
        cin >> hi >> wi;
        if (hi < 0 || 300000 < hi) return 1;
        if (wi < 0 || 300000 < wi) return 1;
        hmp[hi]++;
        wmp[wi]++;
        hmax = max(hmax, hmp[hi]);
        wmax = max(wmax, wmp[wi]);
        hw.insert({hi,wi});
    }
    if (hmax < 0 || wmax < 0) return 1;


    vector<int> a;
    for (auto [hi,c] : hmp) {
        if (c>=hmax) a.emplace_back(hi);
    }


    vector<int> b;
    for (auto [wi,c] : wmp) {
        if (c>=wmax) b.emplace_back(wi);
    }

    int ans = hmax + wmax - 1;
    for (auto ai : a) {
        for (auto bi : b) {
            cerr<<ai<<" "<<bi<<endl;
            if (hw.find({ai,bi}) == hw.end()){
                ans = hmax + wmax;
                goto exit;
            }
        }
    }

    exit:
    cout << ans << endl;
}