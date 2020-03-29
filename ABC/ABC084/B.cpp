#include <iostream>
#include <string>

using namespace std;

int main() {
    int a,b;
    string s;
    cin >> a >> b >> s;
    bool ans = true;
    for (int i=0; i<a; i++) {
        if (s[i] < '0' || '9' < s[i])
            ans = false;
    }

    if (s[a] != '-') ans = false;

    for (int i=a+1; i<=a+b; i++) {
        if (s[i] < '0' || '9' < s[i])
            ans = false;
    }

    cout << (ans? "Yes" : "No") << endl;
}