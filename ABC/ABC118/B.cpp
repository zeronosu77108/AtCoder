#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m+1,0);
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        for (int j=0; j<k; j++) {
            int ai;
            cin >> ai;
            a[ai]++;
        }
    }

    int ans = 0;
    for (int i=1; i<=m; i++) ans += a[i]>=n;
    cout << ans << endl;
}
