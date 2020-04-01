#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int64> a(n);
    vector<int64> b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) b[i] = a[i]-i-1;
    sort(b.begin(), b.end());

    int64 b1 = 0;
    int64 b2 = 0;
    for (int i=0; i<n; i++) b1 += abs(b[i] - b[n/2-1]);
    for (int i=0; i<n; i++) b2 += abs(b[i] - b[n/2]);

    int64 ans = min(b1, b2);
    cout << ans << endl;
}