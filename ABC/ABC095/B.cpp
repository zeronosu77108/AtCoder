#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);

    int amin = INT_MAX;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        amin = min(amin, a[i]);
    }

    x -= accumulate(a.begin(), a.end(), 0);
    cout << n + x / amin << endl;
}