#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+2,0);
    for (int i=1; i<=n; i++) cin >> a[i];

    int dist = 0;
    for (int i=1; i<=n+1; i++) {
        dist += abs(a[i-1] - a[i]);
    }

    for (int i=1; i<=n; i++) {
        int m = abs(a[i-1] - a[i]) + abs(a[i] - a[i+1]);
        int p = abs(a[i-1] - a[i+1]);
        cout << dist - m + p << endl;
    }
}