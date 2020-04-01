#include <iostream>
#include <string>

using namespace std;

int main() {
    string s,t;
    cin >> s >> t;
    int n = s.size();

    s += s;
    bool ans = false;
    for (int i=0; i<n; i++) {
        if (s.substr(i, n) == t) ans = true;
    }

    cout << (ans? "Yes" : "No") << endl;

}