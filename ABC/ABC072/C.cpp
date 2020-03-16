#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        mp[a]++; mp[a-1]++; mp[a+1]++;
    }

    int ans = 0;
    for (auto p : mp) ans = max(ans, p.second);

    cout << ans << endl;
}