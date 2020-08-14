#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    vector s(2,string());
    cin >> s[0] >> s[1];

    long ans = (s[0][0] == s[1][0] ? 3 : 6);
    for (int i=1 + (s[0][0]!=s[1][0]); i<n; i++) {
        if (s[0][i] == s[1][i]) {
            if (s[0][i-1] == s[1][i-1]) {
                ans *= 2;
            }
        } else {
            if (s[0][i-1] == s[1][i-1]) {
                ans *= 2;
            } else {
                ans *= 3;
            }
            i++;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}