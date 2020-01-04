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
    double a,b,c,d;
    string ans;
    cin >> a >> b >> c >> d;
    double ab = b / a;
    double cd = d / c;

    if (ab == cd) ans = "DRAW";
    else if (ab > cd) ans = "TAKAHASHI";
    else ans = "AOKI";

    cout << ans << endl;
}