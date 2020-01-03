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
    int n;
    int ans = 0;
    cin >> n;
    vector<int> a(n);

    for (int i=0; i<n; i++) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);

    if (sum % n != 0) {
        cout << -1 << endl;
        return 0;
    }
    sum /= n;

    for (int i=0; i<n-1; i++) {
        if (a[i] == sum) continue;
        a[i+1] += a[i] - sum;
        ans++;
    }
    cout << ans << endl;
}