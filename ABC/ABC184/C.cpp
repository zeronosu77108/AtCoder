#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;


int main() {
    long r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    complex p1(r1, c1);
    complex p2(r2, c2);

    p2 -= p1;
    p1 -= p1;

    if (p1 == p2) {
        cout << 0 << endl;
        return 0;
    }

    int dist = abs(p2.real()) + abs(p2.imag());
    if (dist<=3 || abs(p2.real())==abs(p2.imag())) {
        cout << 1 << endl;
        return 0;
    }

    if (dist<=6 || (p2.real()+p2.imag())%2==0 || abs(p2.real()-p2.imag())<=3 || abs(p2.real()+p2.imag())<=3) {
        cout << 2 << endl;
        return 0;
    }

    cout << 3 << endl;
}