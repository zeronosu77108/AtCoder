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

#define NG {cout<<"No"<<endl;return 0;}
using int64 = long long;

int main() {
    int h, w;
    cin >> h >> w;
    if (!(h==3&&w==3) && h>=3 && w>=3) NG;

    int _2 = -1;
    int _5 = -1;

    for (int i=1; i<=1000; i++) {
        if (2*(i-1) + 5*i == h*w) {
            _2 = i - 1;
            _5 = i;
        } else if (2*i + 5*(i-1) == h*w) {
            _2 = i;
            _5 = i - 1;
        } else if (2*i + 5*i == h*w) {
            _2 = i;
            _5 = i;
        }
        if (_2 != -1) break;
    }

    if (_2 == -1) NG;

    string ans = "";
    if (_2 > _5) {
        ans += string(2, '2');
        for (int i=0; i<_5; i++) {
            ans += string(5,'5');
            ans += string(2,'2');
        }
    } else {
        ans += string(5,'5');
        for (int i=0; i<_2; i++) {
            ans += string(2,'2');
            ans += string(5,'5');
        }
    }

    cout << "Yes" << endl;
    if (h >= w) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {

                cout << ans[w*i + j];
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << ans[h*j + i];
            }
            cout << endl;
        }
    }
}