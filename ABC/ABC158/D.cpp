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

    int q;
    cin >> q;

    deque<char> ans;
    for (auto c : s) ans.push_back(c);

    bool r = false;
    for (int i=0; i<q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            r = !r;
        }
        else {
            int f;
            char c;
            cin >> f >> c;
            if ((!r && f==1) || (r && f==2)) {
                ans.push_front(c);
            } else {
                ans.push_back(c);
            }
        }
    }

    if(r) {
        while(!ans.empty()) {
            putchar(ans.back());
            ans.pop_back();
        }
    }
    while(!ans.empty()) {
        putchar(ans.front());
        ans.pop_front();
    }
    cout << endl;

}