#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int64 ans = 0;
    for (int i=0; i<n; i++) ans += a[i] - 1;
    cout << ans << endl;
