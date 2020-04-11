#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (x < a[i]) break;
        x -= a[i];
        if (i!=n-1 || x==0) ans++;
    }

    cout << ans << endl;
}
