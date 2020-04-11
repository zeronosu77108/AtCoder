#include <iostream>

using namespace std;
using int64 = long long;

int main() {
    int64 q,h,s,d,n;
    cin >> q >> h >> s >> d >> n;
    int64 _1 = min({4*q, 2*q+h, 2*h, s});
    int64 ans = min(n*_1, (n/2*d + (n%2)*_1));
    cout << ans << endl;
    return 0;
}
