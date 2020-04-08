#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int _max = -1;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        ans += p;
        _max = max(_max, p);
    }

    ans -= _max/2;
    cout << ans << endl;
}
