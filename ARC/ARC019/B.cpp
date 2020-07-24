#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    int cnt = 0;
    for (int i=0; i<n/2; i++) {
        cnt += s[i] != s[n-i-1];
    }

    if (cnt == 0 && n == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (cnt == 1) {
        cout << 24 * 2 + 25 * (n-2) << endl;
        return 0;
    }


    if (cnt == 0 && n%2) {
        cout << 25 * (n-1) << endl;
        return 0;
    }

    cout << 25 * n << endl;
}
