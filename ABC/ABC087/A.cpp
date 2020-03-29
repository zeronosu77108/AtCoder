#include <iostream>

using namespace std;

int main() {
    int x,a,b;
    cin >> x >> a >> b;
    x -= a;
    x %= b;
    cout << x << endl;
}