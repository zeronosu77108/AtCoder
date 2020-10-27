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
    string x;
    cin >> x;

    int n = x.size();
    string rest = "0";
    for (int i=0; i<n; i++) {
        if (x[i] == 'S') rest.push_back(x[i]);
        else {
            if (rest.back() == 'S') rest.pop_back();
            else rest.push_back(x[i]);
        }
    }

    cout << rest.size() - 1 << endl;
}