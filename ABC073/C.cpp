#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    map<long,int> mp;
    for (int i=0; i<n; i++) {
        long a;
        cin >> a;
        mp[a]++;
    }
    
    for (auto p : mp) {
        if (p.second %2 == 1) ans++;
    }
    
    cout << ans << endl;
}
