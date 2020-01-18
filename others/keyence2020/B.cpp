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
typedef pair<int64, int64> P;


int main() {
    int n;
    int64 ans = 0;
    cin >> n;
    vector<int> x(n);
    vector<int> l(n);
    priority_queue<P, vector<P>, greater<>> pq;

    for (int i=0; i<n; i++) {
        int x,l;
        cin >> x >> l;
        pq.emplace(x+l, x-l);
    }

    int64 pre = INT_MIN;
    while(!pq.empty()) {
        int64 start,stop;
        tie(stop, start) = pq.top(); pq.pop();
        if (start < pre) continue;
//        cout << start << " " << stop << endl;
        ans++;
        pre = stop;
    }

    cout << ans << endl;
}