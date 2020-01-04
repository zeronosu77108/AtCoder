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
    int n,m;
    cin >> n >> m;
    n %= 12;
    double nr = (double)n * 30 + (double)m * 0.5;
    double mr = (double)m * 6;

    double ans;
    ans = abs(nr - mr);
    ans = min(ans, abs(360-ans));

    cout << ans << endl;
}