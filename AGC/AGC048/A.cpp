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
#include <unordered_map>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

void solve() {
    const string atcoder = "atcoder";
    string s;
    cin >> s;
    int n = s.size();

    string t = s;
    sort(t.rbegin(), t.rend());
    if (t <= atcoder) {
        cout << -1 << endl;
        return;
    }

    for (int i=0; i<n; i++) {
        for (int j=min(7,i); j>=0; j--) {
            swap(s[i], s[j]);
            if (atcoder < s) {
                cout << i - j << endl;
                return;
            }
            swap(s[i], s[j]);
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) solve();
}