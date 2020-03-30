#include <iostream>

using namespace std;

int main() {
    int n,d,x;
    cin >> n >> d >> x;
    int ans = x + n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        ans += (d-1) / a;
    }

    cout << ans << endl;
}