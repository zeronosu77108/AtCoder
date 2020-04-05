#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int ans = INT_MAX;
    for (int i=0; i+k-1<n; i++) {
        ans = min(ans, abs(a[i]) + abs(a[i+k-1] - a[i]));
        ans = min(ans, abs(a[i+k-1]) + abs(a[i] - a[i+k-1]));
    }

    cout << ans << endl;
}