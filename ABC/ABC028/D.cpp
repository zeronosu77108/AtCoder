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
    long double ans = 1;
    cin >> n >> k;

    ans += (k-1)*(n-k)*6;
    ans += (n-1)*3;

    cout << ans /n/n/n << endl;
}