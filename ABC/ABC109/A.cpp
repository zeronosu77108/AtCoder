#include <iostream>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    bool ans = (a*b)%2;
    cout << (ans? "Yes" : "No") << endl;
}