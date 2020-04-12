#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int,int> mp;
    for (int i=0; i<n; i++) {
        int d;
        cin >> d;
        mp[d]++;
    }

    int m;
    cin >> m;
    bool ans = true;
    for (int i=0; i<m; i++) {
        int t;
        cin >> t;
        if (mp[t] <= 0) ans = false;
        mp[t]--;
    }
    
    cout << (ans? "YES" : "NO") << endl;
}
