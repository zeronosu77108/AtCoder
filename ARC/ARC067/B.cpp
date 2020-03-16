#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using int64 = long long;

int main() {
    int64 n,a,b;
    cin >> n >> a >> b;
    vector<int64> x(n);
    for (int64 i=0; i<n; i++) cin >> x[i];

    int64 ans = 0;
    for (int64 i=1; i<n; i++) {
        ans += min(b, a*abs(x[i-1] - x[i]));
    }

    cout << ans << endl;
}