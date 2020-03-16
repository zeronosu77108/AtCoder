#include <iostream>

using namespace std;

int main(void) {
    int x,a,b;
    cin >> x >> a >> b;
    if (a >= b)
        cout << "delicious" << endl;
    else if (x >= b - a)
        cout << "safe" << endl;
    else
        cout << "dangerous" << endl;
}