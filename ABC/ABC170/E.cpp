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
using P = pair<int64,int64>;

int main() {
    int n,q;
    cin >> n >> q;
    map<int64, multiset<int64>> mq;
    vector<P> be(n);

    for (int64 i=0; i<n; i++) {
        int64 a,b;
        cin >> a >> b;
        mq[b].insert(a);
        be[i] = P(a,b);
    }

    multiset<int64> pq;
    for (auto [a, b] : mq) {
        auto it = b.end();
        it--;
        pq.insert(*it);
    }

    for (int64 i=0; i<q; i++) {
        int64 c,d;
        cin >> c >> d;
        auto [a,b] = be[c-1];
        be[c-1] = P(a,d);


        auto it3 = mq[b].end(); it3--;
        if (*it3 == a) {
            auto deit = pq.find(a);
            pq.erase(deit);
            if (mq[b].size() > 1) {
                it3--;
                pq.insert(*it3);
            }
        }
        auto deit = mq[b].find(a);
        mq[b].erase(deit);


        if (!mq[d].empty()) {
            auto it = mq[d].end();
            it--;
            if (*it < a) {
                auto deit = pq.find(*it);
                pq.erase(deit);
                pq.insert(a);
            }
        } else {
            pq.insert(a);
        }
        mq[d].insert(a);


        auto ans = pq.begin();
        cout << *ans << endl;
    }
}