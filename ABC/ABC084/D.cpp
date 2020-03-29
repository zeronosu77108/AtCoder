#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

vector<bool> primes(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (int64 i=4; i<=n; i+=2) prime[i] = false;
    for (int64 i=3; i<=n; i+=2) {
        if (prime[i]) {
            for (int64 j=i*i; j<=n; j+=i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

int main() {
    int q;
    cin >> q;
    vector<bool> prime = primes(100000);
    vector<int> dp(100002, 0);
    for (int i=1; i<=100000; i++) {
        dp[i] += prime[i] && prime[(i+1)/2];
        dp[i] += dp[i-1];
    }



    for (int i=0; i<q; i++) {
        int l,r;
        cin >> l >> r;
        cout << dp[r] - dp[l-1] << endl;
    }

}