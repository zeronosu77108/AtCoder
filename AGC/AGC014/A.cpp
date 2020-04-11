#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;

    if (a%2==0 && a==b && b==c) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    while(!(a%2 || b%2 || c%2)) {
        int at = b/2 + c/2;
        int bt = a/2 + c/2;
        int ct = a/2 + b/2;
        a = at;
        b = bt;
        c = ct;
        ans++;
    }

    cout << ans << endl;
    return 0;
}
