#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

long long digit(long long n) {
    long long cnt = 0;
    while(n) {
        cnt++;
        n/=10;
    }
    return cnt;
}

int main() {
    long long n;
    cin >> n;
    long long ans = LLONG_MAX;

    for (long long i=1; i*i<=n; i++) {
        if (n%i==0) ans = min(ans, max(digit(i), digit(n/i)));
    }
    cout << ans << endl;
}
