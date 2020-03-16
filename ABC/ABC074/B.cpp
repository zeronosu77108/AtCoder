#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i=0; i<n; i++) cin >> x[i];

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans += min(x[i]*2, abs(k - x[i])*2);
    }

    cout << ans << endl;
}