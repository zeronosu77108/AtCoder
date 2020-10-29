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

    vector a(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    map<int, int> mp;
    int cxor = 0;
    for (const auto& ai : a) mp[ai]++, cxor^=ai;

    if (cxor!=0 || mp.size() > 3) {
        cout << "No" << endl;
        return 0;
    }

    for (const auto& [a,b] : mp) cerr<<a<<" "<<b<<endl;
    bool ans = true;

    switch(mp.size()) {
        case 3:
            if (n%3) ans = false;
            ans = ans && all_of(mp.begin(), mp.end(), [&](const pair<int, int> p) { return p.second == n/3; });
            break;
        case 2:
            if (n%3) ans = false;
            ans = ans && mp[0] == n/3;
            break;
        case 1:
            ans = mp[0] == n;
    }

    cout << (ans? "Yes" : "No") << endl;
}