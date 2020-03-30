#include <iostream>

using namespace std;

int main() {
    int a,b,x;
    cin >> a >> b >> x;
    bool ans = true;
    if (a > x) ans = false;
    if (a+b < x) ans = false;
    cout << (ans? "YES" : "NO") << endl;
}