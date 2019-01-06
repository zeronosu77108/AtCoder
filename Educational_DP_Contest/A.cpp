#include <iostream>
#include <algorithm>

using namespace std;

int n;
int h[10010];

long long dp[100010];

int main(void) {
    cin >> n;

    for (int i=0; i<n; i++) cin >> h[i];

    dp[0] = 0;
    dp[1] = abs( h[0] - h[1]);

    for (int i=0; i<n-1; i++) {
        dp[i+2] = min( (dp[i+1] + abs(h[i+1]-h[i+2])), (dp[i] + abs(h[i]-h[i+2])) );
    }


    cout << dp[n-1] << endl;
}
