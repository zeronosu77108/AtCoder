#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    bool ans = a + b >= c;
    cout << (ans? "Yes" : "No") << endl;
}
