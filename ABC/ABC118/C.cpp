#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {return b? gcd(b,a%b) : a;}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    int ans = a[0];
    for (int i=0; i<n; i++) {
        ans = gcd(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}
