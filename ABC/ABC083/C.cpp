#include <iostream>

using namespace std;

using int64 = long long;

int main() {
    int64 x,y;
    cin >> x >> y;

    int ans = 0;
    while(x <= y) {
        ans++;
        x *= 2;
    }
    cout << ans << endl;
}