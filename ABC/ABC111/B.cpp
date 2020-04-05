#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans;
    for (int i=111; i<=999; i+=111) {
        if (n <= i) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}