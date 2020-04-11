#include <iostream>
#include <string>

using namespace std;

int main() {
    int n,a,b;
    string s;
    cin >> n >> a >> b >> s;

    for (int i=0; i<n; i++) {
        bool pass = false;
        if (s[i] == 'b' && b > 0) {
            b--;
            pass = true;
        }

        if (s[i] == 'a' && a+b > 0) {
            pass = true;
            if (a > 0) a--;
            else b--;
        }

        cout << (pass? "Yes" : "No") << endl;
    }
    return 0;
}

