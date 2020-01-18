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
#define all(x) (x).begin(),(x).end()

typedef long long int64;


int main() {
    string w;
    cin >> w;
    int n = w.size();
    vector<bool> beautiful(26, true);

    for (int i=0; i<n; i++) {
        beautiful[w[i] - 'a'] = !beautiful[w[i] - 'a'];
    }

    if (all_of(all(beautiful), [](bool x){return x;}))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}