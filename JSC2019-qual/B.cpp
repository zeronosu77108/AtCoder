#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int mod = 1000000007;

int main() {
    int n,k;
    int m=0;
    int cnt=0;
    cin >> n >> k;

    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i] < a[j]) cnt++;
            if (i>=j) continue;
            if (a[i] > a[j]) m++;
        }
    }
    // cout << cnt << endl;
    // cout << m << endl;

    // (k-1) * (k-1 + 1) / 2;
    long long ans = ((long long)k*(k-1)/2) % mod;
    ans *= cnt;
    ans %= mod;
    ans += (long long)m*k;
    ans %= mod;

    cout << ans << endl;
}
