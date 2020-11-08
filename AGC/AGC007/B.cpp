#include <iostream>
#include <vector>

using namespace std;

int main() {
    long n;
    cin >> n;

    vector p(n, 0L);
    for (int i=0; i<n; i++) cin >> p[i];

    vector a(n, 0L);
    vector b(n, 0L);
    for (int i=0; i<n; i++) {
        a[i] = (n+1) * (i+1);
        b[n-i-1] = (n+1) * (i+1);
    }

    for (int i=0; i<n; i++) {
        a[p[i]-1] += i + 1;
    }

    for (int i=0; i<n; i++) {
        cout << a[i] << (i+1==n? "\n" : " ");
    }

    for (int i=0; i<n; i++) {
        cout << b[i] << (i+1==n? "\n" : " ");
    }

}