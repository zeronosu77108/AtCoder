#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for (int i=0; i<m; i++) cin >> b[i];

    int ans = 0;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int i=0; i<m; i++) {
            int a;
            cin >> a;
            sum += a*b[i];
        }
        if (sum > -c) ans++;
    }

    cout << ans << endl;
}
