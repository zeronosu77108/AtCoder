#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> a(4);
    for (int i=0; i<4; i++) a[i] = s[i] - '0';

    string ans;
    for (int i=0; i<(1<<3); i++) {
        int cnt = a[0];
        string tmp = to_string(a[0]);
        for (int j=0; j<3; j++) {
            if (i>>j&1) {
                cnt += a[j+1];
                tmp += "+" + to_string(a[j+1]);
            }
            else {
                cnt -= a[j+1];
                tmp += "-" + to_string(a[j+1]);
            }
        }
        if (cnt == 7) ans = tmp;
    }

    cout << ans << "=7" << endl;
}