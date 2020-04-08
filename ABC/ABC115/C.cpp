#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i=0; i<n; i++) cin >> h[i];
    sort(h.begin(), h.end());

    int ans = INT_MAX;
    for (int i=0; i+k-1<n; i++) {
        ans = min(ans, abs(h[i] - h[i+k-1]));
    }

    cout << ans << endl;
}
