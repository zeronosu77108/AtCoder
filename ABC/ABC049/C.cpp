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

    while(ans && !s.empty()) {

        string s5 = (n>=5? s.substr(n-5, 5) : "");
        string s6 = (n>=6? s.substr(n-6, 6) : "");
        string s7 = (n>=7? s.substr(n-7, 7) : "");


        if (s5 == "dream" || s5 == "erase") {
            for (int _ = 0; _<5; _++) s.pop_back();
        } else if (s6 == "eraser") {
            for (int _ = 0; _<6; _++) s.pop_back();
        } else if (s7 == "dreamer") {
            for (int _ = 0; _<7; _++) s.pop_back();
        } else ans = false;


        n = s.size();
    }

    cout << (ans? "YES" : "NO") << endl;
}