#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s,t;
    cin >> n >> s >> t;

    int ans = 2*n;
    for (int i=0; i<n; i++) {
        int j = 0;
        bool f = true;
        while (j < n) {
            if (i+j >= n) break;
            if (s[i+j] != t[j]) {
                f = false;
                break;
            }
            j++;
        }
        if (f) ans = min(ans, i+n);
    }

    cout << ans << endl;
}
