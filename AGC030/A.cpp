#include <iostream>

using namespace std;

int main(void) {
    int a,b,c;
    cin >> a;  cin >> b;  cin >> c;

    int ans = b;

    if( a+b >= c ) {
        ans += c;
    } else {
        ans += a+b + 1;
    }

    cout << ans << endl;
}
