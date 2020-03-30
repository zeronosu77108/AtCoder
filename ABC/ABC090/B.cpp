#include <iostream>
#include <string>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    int ans = 0;
    for (int i=a; i<=b; i++) {
        string s = to_string(i);
        bool r = true;
        for (int j=0; j<s.size(); j++)
            if (s[j] != s[s.size()-j-1]) r = false;
        if (r) ans++;
    }

    cout << ans << endl;
}