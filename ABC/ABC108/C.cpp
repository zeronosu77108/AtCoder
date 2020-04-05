#include <iostream>

using namespace std;
using int64 = long long;

int main() {
    int64 n,k;
    cin >> n >> k;
    int64 ans = (n/k) * (n/k) * (n/k);
    if (k % 2 == 0) {
        int64 t = (n/k);
        if (n%k >= k/2) t++;
        ans += t * t * t;
    }

    cout << ans << endl;
}