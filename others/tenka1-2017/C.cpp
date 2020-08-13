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
    long double N;
    cin >> N;

    for (int64 h=1; h<=3500; h++) {
        for (int64 n=1; n<=3500; n++) {
            long double tmp = 4 * h * n - N * n - N * h;
            if (tmp <= 0) continue;
            long double w = N * h * n / tmp;
            if (ceil(w) == floor(w)) {
                cout << h << " " << n << " " << (int64)w << endl;
                return 0;
            }
        }
    }
}
/*
 * 4/N = 1/h + 1/n + 1/w
 * 4/N - 1/h - 1/n = 1/w
 * 4/N - 1/h - 1/n = 1/w
 * 4h/Nh - N/Nh
 * 4h-N/Nh - 1/n = 1/w
 * (4h-N)*n/Nhn - Nh/Nhn = 1/w
 * (4hn - Nn - Nh)/Nhn = 1/w
 * Nhn/(4hn-Nn-Nh) = w
 */