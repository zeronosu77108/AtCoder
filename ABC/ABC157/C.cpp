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
    int n,m;
    cin >> n >> m;
    string ans_str(n,'-');
    vector<bool> used(n,false);
    bool ans = true;

    for (int i=0; i<m; i++) {
        int s,c;
        cin >> s >> c;
        s--;
        if (!used[s] || (ans_str[s]-'0' == c)) {
            ans_str[s] = c + '0';
            used[s] = true;
        } else {
            ans = false;
            break;
        }
    }
    if (n>1 && ans_str[0] =='0') ans = false;

    if (ans) {
        if (n>1 && ans_str[0] == '-') ans_str[0] = '1';

        for (int i=0; i<n; i++) {
            if (ans_str[i] == '-') ans_str[i] = '0';
        }
    }


    cout << (ans? ans_str : "-1") << endl;
}