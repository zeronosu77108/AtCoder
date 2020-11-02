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
    string s;
    cin >> s;
    int n = s.size();

    map<char, int> mp;
    for (const auto& c : s) mp[c]++;

    bool ans = false;
    for (int i=1; i<1000; i++) {
        if (i%8 != 0) continue;
        map<char, int> tmp = mp;
        int t = i;
        int d = 0;
        while(t!=0) d++,t/=10;

        string st = string(max(0, min(3,n)-d), '0') + to_string(i);
        while(!st.empty()) {
            if (tmp[st.back()] <= 0) break;
            tmp[st.back()]--;
            st.pop_back();
        }

        if (!st.empty()) continue;
        ans = true;
    }

    cout << (ans? "Yes" : "No") << endl;
}