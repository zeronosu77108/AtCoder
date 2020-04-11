#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;
    auto c = [](char x){return x == '9';};
    if (all_of(s.begin()+1, s.end(), c)) {
        ans = s[0] - '0';
    } else {
        ans = s[0] - '1';
    }
    ans += (n-1)*9;
        
    cout << ans << endl;
}
