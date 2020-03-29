#include <iostream>

using namespace std;

int main() {
    int n,a;
    cin >> n >> a;

    bool ans = n % 500 <= a;
    cout << (ans? "Yes" : "No") << endl;
}