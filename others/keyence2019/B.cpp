#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    const string t = "keyence";
    
    bool ans = false;
    for (int i=0; i<=7; i++) {
        for (int j=i; j<n; j++) {
            string ss;
            ss = s.substr(0,i);
            ss += s.substr(j,n-i);
            if (ss == t) ans = true;
        }
    }
    cout << (ans? "YES" : "NO") << endl;
}

