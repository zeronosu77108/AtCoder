#include <iostream>

using namespace std;

int main() {
    int a,b,c,x;
    cin >> a >> b >> c >> x;

    int ans = 0;
    for (int i=0; i<=a; i++) {
        for (int j=0; j<=b; j++) {
            int nc = (x - 500*i - 100*j) / 50;
            if (nc < 0 || c < nc) continue;
            ans++;
        }
    }
    cout << ans << endl;
}