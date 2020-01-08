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
    int64 n,k;
    int64 ans = 0;
    cin >> n >> k;
    vector<int64> a(n);
    for (int64 i=0; i<n; i++) cin>>a[i];

    int64 tmp_sum = 0;
    int64 cnt = 0;
    int64 r = 0;
    for (int64 l=0; l<n; l++) {
        while(r<n && cnt!=k) tmp_sum += a[r++],cnt++;
        if (cnt != k) break;
        ans += tmp_sum;
        tmp_sum -= a[l];
        cnt--;
    }

    cout << ans << endl;
}