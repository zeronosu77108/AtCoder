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
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    int ans = t;

    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=1; i<n; i++) {
        ans += min(t, a[i] - a[i-1]);
    }

    cout << ans << endl;
}