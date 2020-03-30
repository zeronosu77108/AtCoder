#include <iostream>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    bool ans = a<=8 && b<=8;

    cout << (ans? "Yay!" : ":(") << endl;
}