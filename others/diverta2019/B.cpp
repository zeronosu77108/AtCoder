#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> rgb(3);
    int n;
    for (int i=0; i<3; i++) cin >> rgb[i];
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i=0; i<3; i++) {
        for (int j=0; j<=n-rgb[i]; j++) {
            dp[j + rgb[i]] += dp[j];
        }
    }
    cout << dp[n] << endl;
}
