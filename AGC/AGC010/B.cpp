#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    long n;
    cin >> n;

    vector a(n, 0L);
    for (int i=0; i<n; i++) cin >> a[i];
    long asum = accumulate(a.begin(), a.end(), 0L);

    if (asum % (n*(n+1)/2) != 0) {
        cout << "NO" << endl;
        return 0;
    }

    long m = asum / (n*(n+1)/2);

    vector d(n, 0L);
    for (int i=0; i<n; i++) d[i] = a[(i+1) % n] - a[i] - m;

    bool ans = true;
    long c = 0;
    for (auto di : d) {
        if (di > 0 || di%n != 0) {
            ans = false;
            break;
        }
    }

    cout << (ans? "YES" : "NO") << endl;
}