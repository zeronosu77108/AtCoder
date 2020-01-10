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

typedef long long int64;


int main() {
    int64 n,t,q;
    cin >> n >> t >> q;
    vector<int64> ans(n,LONG_MIN);
    vector<int64> stop;
    vector<int64> a(n);
    vector<int64> w,e;
    vector<int64> d(n);
    for (int64 i=0; i<n; i++) {
        cin >> a[i] >> d[i];
        if (d[i] == 1) w.push_back(a[i]);
        else e.push_back(a[i]);
    }

    for (int64 i=0; i<n-1; i++) {
        if (d[i] == 1 && d[i+1] == 2) {
            if (abs(a[i+1]-a[i])/2 > t) continue;
            int64 dist = (a[i]+a[i+1])/2;
            ans[i] = dist;
            ans[i+1] = dist;
            stop.push_back(dist);
        }
    }
    sort(stop.begin(), stop.end());

    for (int64 i=0; i<n; i++) {
        if (ans[i] != LONG_MIN) continue;
        auto it = lower_bound(stop.begin(), stop.end(), a[i]);
        if (d[i] == 1) {
            ans[i] = a[i] + t;
            if (it == stop.end()) continue;
            ans[i] = min(ans[i], *it);
        } else {
            ans[i] = a[i]-t;
            if (it == stop.begin()) continue;
            it--;
            ans[i] = max(ans[i], *it);
        }
    }


    for (int64 i=0; i<q; i++) {
        int64 x; cin>>x; x--;
        cout << ans[x] << endl;
    }
}