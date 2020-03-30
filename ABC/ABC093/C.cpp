#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int sum = max({a,b,c}) * 3;
    if (sum%2 != (a+b+c)%2) sum += 3;
    int ans = sum - a - b - c;
    ans /= 2;

    cout << ans << endl;
}