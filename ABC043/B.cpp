#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());

    string ans = "";
    int cnt = 0;
    for (int i=0; i<n; i++) {
        while(s[i] == 'B') i++,cnt++;
        if (cnt > 0) {
            cnt--;
            continue;
        }

        ans += s[i];
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}