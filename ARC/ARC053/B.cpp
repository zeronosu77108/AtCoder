#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    map<char,int> mp;

    for (int i=0; i<n; i++) mp[s[i]]++;
    int odd = 0;
    for (auto p : mp)
        if (p.second % 2) odd++;

    if (odd == 0) cout << n << endl;
    else {
        cout << (n-odd)/2/odd*2+1 << endl;
    }
}
