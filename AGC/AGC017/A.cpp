#include <iostream>
#include <vector>

using namespace std;
using int64 = long;

// nCr = n! / (n-r)!r!
int64 nCr(int64 n, int64 r) {
    if (n <= r) return 1;
    __int128 nn = 1;
    __int128 rr = 1;
    for (__int128 i=0; i<r; i++) {
        nn *= n - i;
        rr *= i+1;
    }
    return nn / rr;
}

int main () {
    int n,p;
    cin >> n >> p;
    vector a(n,0);
    for (int i=0; i<n; i++) cin >> a[i];

    vector cnt(2,0);
    for (const auto &item : a) cnt[item%2]++;

    int64 ans = (1LL << cnt[0]);
    int64 tmp = 0;
    for (int64 i=p; i<=cnt[1]; i+=2) tmp += nCr(cnt[1], i);
    ans *= tmp;

    cout << ans << endl;
}