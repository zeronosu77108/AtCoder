#include <iostream>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if ( a <= 5 ) {
        b = 0;
    } else if ( a <= 12 ) {
        b /= 2;
    }

    cout << b << endl;
}
