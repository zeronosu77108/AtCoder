#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n,m;
    cin >> n >> m;
    long long nmax=-1;
    long long nmin=9999999999;
    for(long long i=0; i<m; i++) {
        long long l,r;
        cin >> l >> r;
        nmax = max(nmax, l);
        nmin = min(nmin, r);
    }

    long long ans = abs(nmin - nmax) + 1;
    if ( nmin < nmax ) {
        ans = 0;
    }
    cout << ans << endl;
}
