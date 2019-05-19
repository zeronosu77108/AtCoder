#include <iostream>

using namespace std;

int main(void) {
    long long n,k;
    double ans = 0.0;
    cin >> n >> k;

    for (long long i=1; i<=n; i++) {
        double sum = i;
        double tmp = n;

        while( sum <= k-1 ) {
            sum *= 2.0;
            tmp *= 2.0;
        }
        ans += (1.0 / tmp);
        // ans += tmp;
    }

    // cout << ans << endl;
    printf("%.16f\n", ans);
}
