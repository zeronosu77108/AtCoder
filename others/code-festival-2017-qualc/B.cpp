#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    int ans = 1;
    for (int i=0; i<n; i++) ans *= 3;

    int d = 1;
    for (int i=0; i<n; i++) {
        if (a[i]%2 == 0) d*=2;
    }
    ans -= d;
    cout << ans << endl;
}
