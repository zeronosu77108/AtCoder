#include <iostream>
#include <map>

using namespace std;

int main() {
    int s;
    cin >> s;
    int ans = 1;

    map<int,bool> mp;
    while(!mp[s]) {
        mp[s] = true;
        s = (s%2? 3*s+1 : s/2);
        ans++;
    }
    cout << ans << endl;
}
