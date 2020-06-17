#include <iostream>
#include <vector>
#include <map>

using namespace std;
using int64 = long long;

int main() {
    int64 n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int64> cnt(n,0);
    map<int64,int64> mp;
    mp[-1] = 3;

    for (int i=0; i<n; i++) {
        cnt[i] = mp[a[i] - 1];
        mp[a[i]-1]--;
        mp[a[i]]++;
    }


    const int MOD = 1000000007;
    int64 ans = 1;
    for (int i=0; i<n; i++) {
        ans *= cnt[i];
        ans %= MOD;
    }

    cout << ans << endl;
}