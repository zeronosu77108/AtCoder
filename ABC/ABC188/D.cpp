//
// Created by zeronosu77108 on Jan 10, 2021.
//
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
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;
using TP = tuple<int, int, int>;

int main() {
    long n, c;
    cin >> n >> c;

    priority_queue<TP, vector<TP>, greater<>> pq;
    for (int i=0; i<n; i++) {
        long a, b, c;
        cin >> a >> b >> c;
        pq.emplace(a, 0, c);
        pq.emplace(b, 1, c);
    }


    long ans = 0;
    long sum = 0;
    long d = 0;
    vector<long> av;
    while(!pq.empty()) {
        const auto [a, t, ci] = pq.top(); pq.pop();
        if (!t) {
            ans += (a - d) * min(c, sum);
            sum += ci;
            d = a;
            continue;
        }

        ans += (a - d + 1) * min(c, sum);
        d = a + 1;
        sum -= ci;
    }

    cout << ans << endl;
}
