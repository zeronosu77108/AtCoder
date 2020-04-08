#include <iostream>

using namespace std;

int main() {
    int n,l;
    cin >> n >> l;
    int ans = INT_MAX;
    for (int i=0; i<n; i++) {
        int c,t;
        cin >> c >> t;
        if (t > l) continue;
        ans = min(ans, c);
    }

    if (ans != INT_MAX) {
        cout << ans << endl;
    } else {
        cout << "TLE" << endl;
    }
}