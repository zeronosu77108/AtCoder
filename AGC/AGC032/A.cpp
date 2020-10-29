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
    int n;
    cin >> n;
    vector b(n, 0);
    for (int i=0; i<n; i++) cin >>b[i];

    vector<int> ans;
    while(!b.empty()) {
        bool f = false;
        for (int i=b.size()-1; i>=0; i--) {
            if (b[i] == i+1) {
                ans.emplace_back(b[i]);
                b.erase(b.begin()+i);
                f = true;
                break;
            }
        }
        if (!f) break;
    }

    reverse(ans.begin(), ans.end());
    if (b.empty()) {
        for (auto a : ans) cout<<a<<endl;
    } else {
        cout << -1 << endl;
    }
}