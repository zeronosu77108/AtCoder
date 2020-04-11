#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    map<int,int> mp;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (mp[a[i]] == i+1) {
            ans++;
        }
        mp[i+1] = a[i];
    }


    cout << ans << endl;
}
