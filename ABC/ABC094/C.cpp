#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    b = a;
    sort(b.begin(), b.end());

    double mid = b[n/2-1] + b[n/2];
    mid /= 2;
    for (int i=0; i<n; i++) {
        int ans =0;
        if (a[i] <= mid) ans = b[n/2];
        else ans = b[n/2-1];

        cout << ans << endl;
    }
}