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
    int64 n,a,b;
    cin >> n >> a >> b;
    int64 diff =  abs(a-b);
    if (diff % 2 == 0) {
        cout << diff/2 << endl;
        return 0;
    }

    int64 ans = (a-1) + 1 + (diff+1) /2;
    ans = min(ans, (n-b) + 1 + (diff+1) /2);

    cout << ans << endl;
    return 0;
}
