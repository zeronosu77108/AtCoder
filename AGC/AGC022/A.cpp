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
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

bool ok(const string& s) {
    bool res = true;
    vector cnt(26, 0);
    for (auto c : s) {
        cnt[c - 'a']++;
        if (cnt[c-'a'] >= 2) res = false;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    set<char> set;
    map<char, int> mp;
    for (char c='a'; c<='z'; c++) set.insert(c);

    for (const auto& c : s) {
        set.erase(c);
        mp[c]++;
    }

    string ans = s;
    char pre = 'a' - 1;
    while(true) {
        auto it = set.upper_bound(pre);
        if (ok(ans) && it != set.end()) {
            ans += *it;
            break;
        }
        if (ans.empty()) break;
        pre = ans.back();
        mp[pre]--;
        if (mp[pre] <= 0) set.insert(pre);
        ans.pop_back();
    }

    if (ans.empty()) ans = "-1";
    cout << ans << endl;
}