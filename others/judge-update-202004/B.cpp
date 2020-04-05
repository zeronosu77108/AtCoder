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
    int n;
    cin >> n;
    vector<int> r;
    vector<int> b;
    for (int i=0; i<n; i++) {
        int x;
        char c;
        cin >> x >> c;
        if (c == 'R') r.push_back(x);
        else b.push_back(x);
    }

    sort(r.begin(), r.end());
    sort(b.begin(), b.end());

    for (auto ri : r) cout << ri << endl;
    for (auto bi : b) cout << bi << endl;
}