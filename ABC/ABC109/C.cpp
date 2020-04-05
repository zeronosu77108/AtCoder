#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

int64 gcd(int64 a, int64 b) { return b? gcd(b,a%b) : a;}

int main() {
    int64 n,x;
    cin >> n >> x;
    vector<int64> a(n);
    for (int i=0; i<n; i++) cin >> a[i];


    int64 ans = abs(a[0] - x);
    for (int i=0; i<n; i++) {
        ans = gcd(ans, abs(a[i] - x));
        x = a[i];
    }

    cout << ans << endl;
}