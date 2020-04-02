#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 0;
    string ans;
    while (n != 0) {
        if (n & 1) {
            ans += "1";
            if (i%2==0) n -= 1;
            else n += 1;
        }
        else ans += "0";
        n /= 2;
        i++;
    }
    if (ans == "") ans = "0";
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}