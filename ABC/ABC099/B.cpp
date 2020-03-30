#include <iostream>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    int n = b - a;
    cout << n*(n-1)/2 - a << endl;
}