#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    int ans = 1;
    for (int i=2; i<=x; i++) {
        int t = i*i;
        while(t <= x) {
            ans = max(ans, t);
            t *= i;
        }
    }
    cout << ans << endl;
}