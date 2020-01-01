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
    int64 n,s,t,w;
    int64 ans = 0;
    cin >> n >> s >> t >> w;
    if (s <= w && w <= t) ans++;

    for (int64 i=1; i<n; i++) {
        int64 a; cin>>a;
        w += a;
        if (s <= w && w <= t) ans++;
    }

    cout << ans << endl;
}