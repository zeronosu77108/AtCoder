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

const int mod = 1000000007;

int main() {
    int64 a,b,c;
    cin >> a >> b >> c;
    int64 ans = a*b % mod;
    ans *= c;
    ans %= mod;

    cout << ans << endl;
}