#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    long n;
    long ans = 0;
    cin >> n;
    vector<long> a(n);

    for (int i=0; i<n; i++) cin>>a[i];

    long r,sum;
    r = sum = 0;
    for (long l=0; l<n; l++) {
        while(r<n && (sum^a[r])==(sum+a[r])) {
            sum += a[r];
            r++;
        }

        ans += r - l;
        sum -= a[l];
    }

    cout << ans << endl;
}