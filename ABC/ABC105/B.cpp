#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool ans = false;
    for (int i=0; i<=25; i++) {
        for (int j=0; j<=15; j++) {
            if (4*i + 7*j == n) ans = true;
        }
    }
    cout << (ans? "Yes" : "No") << endl;
}