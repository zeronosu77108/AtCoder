#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i=0; i<n-1; i++) {
        ans++;
        while(i<n-1 && a[i] == a[i+1]) i++;
        if (i>=n-1) continue;
        if (a[i] < a[i+1])
            while (i<n-1 && a[i]<=a[i+1]) i++;
        else if (a[i] > a[i+1])
            while (i<n-1 && a[i]>=a[i+1]) i++;
        if (i == n-2) ans++;
    }
    
    cout << ans << endl;
}
