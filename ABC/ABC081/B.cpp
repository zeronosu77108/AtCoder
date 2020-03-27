#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = INT_MAX;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        int cnt = 0;
        while(a%2 == 0) {
            a /= 2;
            cnt++;
        }

        ans = min(ans, cnt);
    }
    cout << ans << endl;
}