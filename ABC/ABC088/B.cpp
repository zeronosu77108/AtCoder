#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int alice = 0;
    int bob = 0;
    for (int i=0; i<n; i+=2) {
        alice += a[i];
        if (i+1 < n) bob += a[i+1];
    }

    cout << alice - bob << endl;
}