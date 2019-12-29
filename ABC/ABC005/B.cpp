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
    int ans = INT_MAX;
    cin >> n;

    for (int i=0; i<n; i++) {
        int t;
        cin >> t;
        ans = min(ans, t);
    }

    cout << ans << endl;
}