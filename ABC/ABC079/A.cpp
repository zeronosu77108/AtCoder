#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<pair<char,int>> cnt;
    cnt.emplace_back(s[0],0);

    bool ans = false;
    for (int i=0; i<n; i++) {
        if (cnt.back().first == s[i]) cnt.back().second++;
        else cnt.emplace_back(s[i], 1);

        if (cnt.back().second >= 3) ans = true;
    }


    cout << (ans? "Yes" : "No") << endl;
}