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
    for (int i=1; i*i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (n < i*j) continue;
            ans = min(ans, abs(n-i*j) + abs(i-j));
        }
    }
    cout << ans << endl;
}