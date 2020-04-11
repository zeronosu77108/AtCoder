#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    map<char, bool> mp;
    for (int i=0; i<n; i++) {
        mp[s[i]] = true;
    }

    bool ans = false;
    ans |= mp.size() == 4;
    ans |= mp['N'] && mp['S'] && !mp['W'] && !mp['E'];
    ans |= !mp['N'] && !mp['S'] && mp['W'] && mp['E'];
    cout << (ans? "Yes" : "No") << endl;
}
