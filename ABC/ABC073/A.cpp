#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool ans = (n%10 == 9) || (n/10 == 9);
    cout << (ans? "Yes" : "No") << endl;
}