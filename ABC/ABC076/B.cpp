#include <iostream>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int ans = 1;
    for (int i=0; i<n; i++) {
        ans = min(2*ans, ans + k);
    }

    cout << ans << endl;
}