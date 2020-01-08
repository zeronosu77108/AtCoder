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
    int64 ans = 0;
    cin >> n;
    vector<int64> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int64 pre_max = -1;
    int r = 0;
    for (int l=0; l<n; l++) {
        if (l > r) r = l;
        while(r<n-1 && a[r] < a[r+1]) r++;
//        cout << l << " => " << r << " " << ans << endl;
        ans += (r - l + 1);
    }

    cout << ans << endl;
}