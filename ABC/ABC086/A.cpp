#include <iostream>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    bool ans = a%2 && b%2;
    cout << (ans? "Odd" : "Even") << endl;
}