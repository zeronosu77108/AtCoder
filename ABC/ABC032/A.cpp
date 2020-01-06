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

int gcd(int a, int b) {
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

int main() {
    int a,b,n;
    cin >> a >> b >> n;
    int lcm = a*b/gcd(a,b);
    int ans = lcm;

    while(ans < n) ans += lcm;

    cout << ans << endl;
}