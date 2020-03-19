#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using int64 = long long;

int main() {
    int n;
    cin >> n;

    vector<vector<int64>> a(n, vector<int64>(n));
    vector<vector<int64>> d(n, vector<int64>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j];
        }
    }

    bool f = true;
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == k || k == j) continue;
                if (d[i][j] > d[i][k] + d[k][j]) {
                    f = false;
                } else if (d[i][j] == d[i][k] + d[k][j]) {
                    a[i][j] = 0;
                }
            }
        }
    }



    if (!f) {
        cout << -1 << endl;
        return 0;
    }

    int64 ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i][j] == d[i][j])
                ans += a[i][j];
        }
    }

    cout << ans << endl;

}