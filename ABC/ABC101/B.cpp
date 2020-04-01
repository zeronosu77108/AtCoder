#include <iostream>

using namespace std;

int s(int n) {
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
    bool ans = n % s(n) == 0;
    cout << (ans? "Yes" : "No") << endl;
}