#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n,m;
    map<string, int> mp;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        mp[s]--;
    }

    int ans = 0;
    for (auto p : mp) ans = max(ans, p.second);

    cout << ans << endl;
}