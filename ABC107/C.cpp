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
    int64 n,k;
    int64 ans = INT_MAX;
    cin >> n >> k;
    vector<int64> x(n);

    for(int64 i=0; i<n; i++) cin>>x[i];

    for(int64 i=0; i+k<=n; i++) {
        int64 r = i + k - 1;
        ans = min(ans, abs(x[i]) + abs(x[i] - x[r]));
        ans = min(ans, abs(x[r]) + abs(x[r] - x[i]));
    }

    if (n == 1) ans = abs(x[0]);
    cout << ans << endl;
}