#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string s;
    set<string> ans;
    while(cin >> s) {
        for (int i=0; i<s.size(); i++) {
            string t = "";
            if (s[i]!='@') continue;
            i++;
            while(i<s.size() && 'a'<=s[i] && s[i]<='z')
                t += s[i++];
            if (t.size() > 0) ans.insert(t);
            if (s[i] == '@') i--;
        }
    }


    for (auto s : ans) {
        cout << s << endl;
    }
}