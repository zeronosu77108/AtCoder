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
    bool ans = true;
    {
        string r = s;
        reverse(r.begin(), r.end());
        if (r != s) ans = false;
    }

    {
        string t = s.substr(0, (n-1)/2);
        string r = t;
        reverse(r.begin(), r.end());
        if (r != t) ans = false;
    }

    {
        string t = s.substr((n+3)/2-1, n);
        string r = t;
        reverse(r.begin(), r.end());
        if (r != t) ans = false;
    }

    cout << (ans? "Yes" : "No") << endl;
}