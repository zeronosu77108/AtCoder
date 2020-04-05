#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int ans = a*10 + b + c;
    ans = max(ans, a + b*10 + c);
    ans = max(ans, a + b + c*10);

    cout << ans << endl;
}