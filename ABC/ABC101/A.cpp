#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    for (auto c : s) {
        if (c == '+') ans++;
        if (c == '-') ans--;
    }

    cout << ans << endl;
}