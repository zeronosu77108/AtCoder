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
    int n,k,s;
    cin >> n >> k >> s;
    vector<int64> a(n);
    for (int i=0; i<k; i++) {
        a[i] = s;
    }

    int si = (s==1? s+1 : s-1);
    for (int i=k; i<n; i++) {
        a[i] = si;
    }

    for (auto ai : a) cout << ai << " ";
    cout << endl;
}