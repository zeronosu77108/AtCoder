#include <iostream>

using namespace std;
using int64 = long long;

int main() {
    int n,k;
    cin >> n >> k;

    int64 ans = 0;
    for (int i=1; i<=n; i++) {
        if (i <= k) continue;
        ans += (n/i) * (i-k);
        ans += max(0, n%i - k + 1);
        if (k == 0) ans--;
    }

    cout << ans << endl;
}