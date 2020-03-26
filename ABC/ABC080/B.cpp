#include <iostream>

using namespace std;

int f(int n) {
    int res = 0;
    while(n != 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    if (n % f(n) == 0 ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}