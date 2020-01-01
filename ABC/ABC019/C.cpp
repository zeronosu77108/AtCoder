#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;


int main() {
    int64 n;
    int64 ans = 0;
    cin >> n;
    vector<int64> a(n);
    map<int64, bool> mp;

    for (int64 i=0; i<n; i++) {
        int64 a; cin>>a;
        while(a%2==0) a/=2;
        if (mp[a]) continue;
        mp[a] = true;
        ans++;
    }

    cout << ans << endl;
}