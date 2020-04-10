#include <iostream>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if (b%a) {
        cout << b - a << endl;
    } else {
        cout << a + b << endl;
    }
}
