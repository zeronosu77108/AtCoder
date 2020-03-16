#include <iostream>
#include <string>

using namespace std;

int main() {
    string s,t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());

    bool ans = s < t;
    cout << (ans? "Yes" : "No") << endl;
}