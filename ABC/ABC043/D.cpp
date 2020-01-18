#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cout<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}


typedef long long int64;


int main() {
    string s;
    cin >> s;
    int n = s.size();

    if (n == 2 && s[0] == s[1]) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }

    for (int i=0; i<n-2; i++) {
        if (s[i] == s[i+1]) {
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }

        if (s[i+1] == s[i+2]) {
            cout << i+2 << " " << i+3 << endl;
            return 0;
        }

        if (s[i] == s[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
}