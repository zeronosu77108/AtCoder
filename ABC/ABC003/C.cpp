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
    int n,k;
    double ans = 0;
    cin >> n >> k;

    vector<int> r(n);
    for (int i=0; i<n; i++) cin>>r[i];
    sort(r.rbegin(), r.rend());

    for (int i=k-1; i>=0; i--) {
        ans = (ans + r[i]) / 2;
    }

    cout << ans << endl;

}