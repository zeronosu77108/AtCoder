#include <iostream>

using namespace std;
using int64 = long long;

int main() {
    int64 n,a,b;
    cin >> n >> a >> b;
    int64 ans = b*(n-2) - a*(n-2) + 1;
    if (n==1) ans = a==b;
    if (a>b) ans = 0;
    cout << ans << endl;
}
