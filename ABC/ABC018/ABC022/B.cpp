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
    int n;
    int ans = 0;
    cin >> n;
    map<int,bool> mp;
    for (int i=0; i<n; i++) {
        int a; cin>>a;
        if (mp[a]) ans++;
        mp[a] = true;
    }

    cout << ans << endl;
}