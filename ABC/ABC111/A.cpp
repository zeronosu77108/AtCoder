#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i=0; i<n; i++) {
        if (s[i] == '1') s[i] = '9';
        else if (s[i] == '9') s[i] = '1';
    }

    cout << s << endl;
}