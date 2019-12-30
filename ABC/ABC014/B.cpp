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
    int n,x;
    int ans = 0;
    cin >> n >> x;
    vector<int> b(n);
    for (int i=0; i<n; i++) cin>>b[i];

    for (int i=0; i<n; i++) {
        if ((x>>i)&1) ans += b[i];
    }

    cout << ans << endl;

}