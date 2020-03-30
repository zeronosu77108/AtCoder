#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    bool ans = s == "abc";

    cout << (ans? "Yes" : "No") << endl;
}